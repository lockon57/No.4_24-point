// Function.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "math.h"
#include "express.h"
#include <ctype.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_SERIAL(CExpression, CObject, 0)

void CExpression::elibmem ( arbore a)
{
if (a==NULL) return;
if (a->left!=NULL) elibmem(a->left);
if (a->right!=NULL) elibmem(a->right);
if (a->operatie == '`')
		delete a->valoarestr;
delete a;
}

CExpression::CExpression()
{
	m_Arbore = NULL;
	m_definitie = "";
	pozitie = 0;
	m_pvariabile = NULL;
}

CExpression::CExpression(CMapVariabile * vars)
{
	m_Arbore = NULL;
	m_definitie = "";
	pozitie = 0;
	m_pvariabile = vars;
}

CExpression::~CExpression()
{
 elibmem (m_Arbore);
}

void CExpression::Serialize(CArchive & ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_definitie;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_definitie;
		m_Arbore = NULL;
		pozitie = 0;
		UpdateArbore();
	}
}

int CExpression::UpdateArbore()
{
	if (m_definitie.IsEmpty())
		return 0;
	elibmem(m_Arbore);
	m_Arbore = NULL;
	pozitie = 0;
	m_Arbore = expresie();
	if (m_definitie[pozitie]!='\0') 
	{
		elibmem(m_Arbore);
		m_Arbore = NULL;
	}

	if (m_Arbore == NULL)
		return pozitie;
	else return -1;
}

CExpression::arbore CExpression::expresie()
{
	arbore nod;
	arbore arb1 = termen();
	arbore arb2;
	if  (arb1 == NULL) return NULL;

	

	while ((m_definitie[pozitie]=='-') || (m_definitie[pozitie]=='+')) 
	{
		nod=new NOD;
		nod->left=arb1;
		nod->operatie=m_definitie[pozitie];
		pozitie++;
		arb2 = termen();
		nod->right=arb2;
		if  (arb2 == NULL) 
		{
			elibmem(nod);
			return NULL;
		}
		arb1 = nod;
	}
	return arb1;
}

CExpression::arbore CExpression::termen()
{
	arbore nod;
	arbore arb1 = putere();
	arbore arb2;
	if  (arb1 == NULL) return NULL;

	

	while ((m_definitie[pozitie]=='*') || (m_definitie[pozitie]=='/')) 
	{
		nod=new NOD;
		nod->left=arb1;
		nod->operatie=m_definitie[pozitie];
		pozitie++;
		arb2 = putere();
		nod->right=arb2;
		if  (arb2 == NULL) 
		{
			elibmem(nod);
			return NULL; 
		}
		arb1 = nod;
	}
	return arb1;
}

CExpression::arbore CExpression::putere()
{
	arbore nod = NULL;
	arbore arb1 = logicalOp();
	arbore arb2;
	if  (arb1 == NULL) return NULL; 

	while (m_definitie[pozitie]=='^') 
	{
		nod=new NOD;
		nod->left=arb1;
		nod->operatie=m_definitie[pozitie];
		pozitie++;
		arb2 = logicalOp();
		nod->right=arb2;
		if  (arb2 == NULL) 
		{
			elibmem(nod);
			return NULL;
		}
		arb1 = nod;
	}
	return arb1;
}


CExpression::arbore CExpression::factor()
{
 arbore nod = NULL,nod2 = NULL,left = NULL;
 while(m_definitie[pozitie] == ' ' && m_definitie[pozitie] != '\0')
	 pozitie++;

 if (m_definitie[pozitie]=='-')
   {
    nod = new NOD;
    left = new NOD;
    left->right=NULL;
    left->left=NULL;
    left->operatie='@';
    left->valoare=-1;
    nod->left=left;
    nod->operatie='*';
    pozitie++;
	nod->right = expresie();
	if (nod->right == NULL) return NULL;
	return nod;   
 }
 if (m_definitie[pozitie]=='(')
    {
      pozitie++;
      nod = expresie();
      if (nod == NULL) return NULL;
	  if (m_definitie[pozitie]!=')')
	  {
		elibmem(nod);
		return NULL;
	  }
	  pozitie++;
	  return nod;
    }
 else if (m_definitie[pozitie]=='|')
	 {
	   pozitie++;
	   nod2 = expresie();
	   if (nod2 == NULL) return NULL;
	   if (m_definitie[pozitie]!='|')
		{
			elibmem(nod);
			return NULL;
		}
	   nod = new NOD;
	   nod->left=nod2;
	   nod->right=NULL;
	   nod->operatie='|';
	   pozitie++;
	   return nod;
	}
     else return identificator();
 return nod;
}

CExpression::arbore CExpression::identificator()
{
	int poz;
	arbore nod = NULL,nod2 = NULL;
	arbore result = NULL;
	poz=pozitie;
	SkipSpaces();
	if (m_definitie[pozitie]=='\0') result  = NULL;
	if (isdigit(m_definitie[pozitie]))
		{
			while  ((isdigit(m_definitie[pozitie]) || (m_definitie[pozitie]=='.')))
					 pozitie++;
			nod = new NOD;
			nod->left = NULL; 
			nod->right = NULL;
			nod->operatie = '@';
			nod->valoare = atof(m_definitie.Mid(poz,pozitie-poz));
			result = nod;
		}
	if (isalpha(m_definitie[pozitie]))
	{/*此处可添加代码以处理函数*/}
	SkipSpaces();
	return result;
        
}

int CExpression::ChangeExpression(CString & expresie)
{
	m_definitie = expresie + '\0' + '\0';
	return UpdateArbore();
}

int code;

int CExpression::Value(double& valoare)
{
  code=0;
  if (m_Arbore == NULL) return -1;
  valoare=vexp(m_Arbore);
  return (code);
}


double CExpression::vexp ( arbore a )
{
double v;
if (a->operatie==NULL) {code=10;return 0;}
switch(a->operatie) 
 {
 case '+' : return( vexp(a->left)+vexp(a->right) );
 case '-' : return( vexp(a->left)-vexp(a->right) );
 case '*' : return( vexp(a->left)*vexp(a->right) );
 case '/' : v=vexp(a->right) ;
			 if (v==0)
			 {code=DIVISION_BY_0;return -vexp(a->left)/0.001;}
			 else
				return(vexp(a->left)/v);
 case 153 : v=vexp(a->left) ;
			 if (v<0) {code=INVALID_DOMAIN;return 0;}
			 else return(sqrt(v));
 case 154 : v=vexp(a->left) ;
			 if (v<=0) {code=INVALID_DOMAIN;return 0;}
			 else return(log(v));
 case '|' : return(fabs(vexp(a->left)));
 case '@' : return (a->valoare);
 //logical operations evaluation
 case '<' : return( vexp(a->left)<vexp(a->right) );
 case '>' : return( vexp(a->left)>vexp(a->right) );
 case '!' : return(!vexp(a->right)) ;
 
 default  : {
				if (m_pvariabile==NULL) 
				{
					code=UNDEFINED_VARIABLE;
					return 0;
				}
				CValue *valoare;
				if (!m_pvariabile->Lookup(*a->valoarestr,valoare))
				{
					code=UNDEFINED_VARIABLE;
					return 0;
				}
				else 
				return valoare->GetValue();
			}
 }
}


CExpression::arbore CExpression::GetArbore()
{
	return m_Arbore;
}


CExpression::CExpression(CExpression & expresie)
{
	*this = expresie;
}

CExpression::arbore CExpression::CloneTree()
{
	return clone(m_Arbore);	
}

void CExpression::AtachVariables(CMapVariabile * vars)
{
	m_pvariabile = vars;
}

CExpression::arbore CExpression::clone(arbore arb)
{
	if (arb == NULL)
		return NULL;
	arbore clonArb = new NOD;
	*clonArb = *arb;
	clonArb->left = clone(arb->left);
	clonArb->right = clone(arb->right);
	return clonArb;
}

CExpression& CExpression::operator=(CExpression &expr)
{
	m_definitie = expr.m_definitie;
	m_pvariabile = expr.m_pvariabile;
	pozitie = 0;
	m_Arbore = expr.CloneTree();
	return *this;
}

void CExpression::SkipSpaces()
{
	while (m_definitie[pozitie]==' ' && m_definitie[pozitie]!='\0')
		pozitie ++;
}

CExpression::arbore CExpression::logicalOp()
{
	arbore nod;
	arbore arb1 = sgOp();
	arbore arb2;
	if  (arb1 == NULL) return NULL;

	while ((m_definitie[pozitie]=='<') || (m_definitie[pozitie]=='>')) 
	{
		nod=new NOD;
		nod->left=arb1;
		nod->operatie=m_definitie[pozitie];
		pozitie++;
		arb2 = sgOp();
		nod->right=arb2;
		if  (arb2 == NULL) 
		{
			elibmem(nod);
			return NULL; 
		}

		arb1 = nod;
	}
	return arb1;
}

CExpression::arbore CExpression::sgOp()
{
	arbore nod = NULL;
	arbore arb2;
	if ((m_definitie[pozitie]=='!')) 
	{
		nod=new NOD;
		nod->left=NULL;
		nod->operatie=m_definitie[pozitie];
		pozitie++;
		arb2 = sgOp();
		nod->right=arb2;
		if  (arb2 == NULL) 
		{
			elibmem(nod);
			return NULL;
		}
	}
	else 
		nod = factor();
	return nod;
}
