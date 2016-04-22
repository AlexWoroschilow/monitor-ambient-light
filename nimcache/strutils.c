/* Generated by Nim Compiler v0.12.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -O3 -fno-strict-aliasing  -I/usr/lib/nim -o /home/sensey/Projects/nim-test/nimcache/strutils.o /home/sensey/Projects/nim-test/nimcache/strutils.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Valueerror4049 Valueerror4049;
typedef struct Exception Exception;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct Cell48947 Cell48947;
typedef struct Cellseq48963 Cellseq48963;
typedef struct Gcheap51018 Gcheap51018;
typedef struct Gcstack51016 Gcstack51016;
typedef struct Cellset48959 Cellset48959;
typedef struct Pagedesc48955 Pagedesc48955;
typedef struct Memregion30891 Memregion30891;
typedef struct Smallchunk30843 Smallchunk30843;
typedef struct Llchunk30885 Llchunk30885;
typedef struct Bigchunk30845 Bigchunk30845;
typedef struct Intset30817 Intset30817;
typedef struct Trunk30813 Trunk30813;
typedef struct Avlnode30889 Avlnode30889;
typedef struct Gcstat51014 Gcstat51014;
typedef struct Basechunk30841 Basechunk30841;
typedef struct Freecell30833 Freecell30833;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY3889) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3894) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3889 marker;
TY3894 deepcopy;
};
struct  TNimObject  {
TNimType* m_type;
};
struct  Exception  {
  TNimObject Sup;
Exception* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
struct  Valueerror4049  {
  Exception Sup;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  Cell48947  {
NI refcount;
TNimType* typ;
};
struct  Cellseq48963  {
NI len;
NI cap;
Cell48947** d;
};
struct  Cellset48959  {
NI counter;
NI max;
Pagedesc48955* head;
Pagedesc48955** data;
};
typedef Smallchunk30843* TY30906[512];
typedef Trunk30813* Trunkbuckets30815[256];
struct  Intset30817  {
Trunkbuckets30815 data;
};
struct  Memregion30891  {
NI minlargeobj;
NI maxlargeobj;
TY30906 freesmallchunks;
Llchunk30885* llmem;
NI currmem;
NI maxmem;
NI freemem;
NI lastsize;
Bigchunk30845* freechunkslist;
Intset30817 chunkstarts;
Avlnode30889* root;
Avlnode30889* deleted;
Avlnode30889* last;
Avlnode30889* freeavlnodes;
};
struct  Gcstat51014  {
NI stackscans;
NI cyclecollections;
NI maxthreshold;
NI maxstacksize;
NI maxstackcells;
NI cycletablesize;
NI64 maxpause;
};
struct  Gcheap51018  {
Gcstack51016* stack;
void* stackbottom;
NI cyclethreshold;
Cellseq48963 zct;
Cellseq48963 decstack;
Cellset48959 cycleroots;
Cellseq48963 tempstack;
NI recgclock;
Memregion30891 region;
Gcstat51014 stat;
};
typedef NI Skiptable102393[256];
typedef NU8 TY162040[32];
typedef NimStringDesc* TY168231[1];
struct  Gcstack51016  {
Gcstack51016* prev;
Gcstack51016* next;
void* starts;
void* pos;
NI maxstacksize;
};
typedef NI TY30822[8];
struct  Pagedesc48955  {
Pagedesc48955* next;
NI key;
TY30822 bits;
};
struct  Basechunk30841  {
NI prevsize;
NI size;
NIM_BOOL used;
};
struct  Smallchunk30843  {
  Basechunk30841 Sup;
Smallchunk30843* next;
Smallchunk30843* prev;
Freecell30833* freelist;
NI free;
NI acc;
NF data;
};
struct  Llchunk30885  {
NI size;
NI acc;
Llchunk30885* next;
};
struct  Bigchunk30845  {
  Basechunk30841 Sup;
Bigchunk30845* next;
Bigchunk30845* prev;
NI align;
NF data;
};
struct  Trunk30813  {
Trunk30813* next;
NI key;
TY30822 bits;
};
typedef Avlnode30889* TY30896[2];
struct  Avlnode30889  {
TY30896 link;
NI key;
NI upperbound;
NI level;
};
struct  Freecell30833  {
Freecell30833* next;
NI zerofield;
};
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI x);
static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NIMCALL(NI, npuParseInt)(NimStringDesc* s, NI* number, NI start);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
static N_INLINE(Cell48947*, usrtocell_52646)(void* usr);
static N_INLINE(void, rtladdzct_54204)(Cell48947* c);
N_NOINLINE(void, addzct_52617)(Cellseq48963* s, Cell48947* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
N_NIMCALL(NimStringDesc*, rawNewString)(NI cap);
N_NIMCALL(void, nsuAddf)(NimStringDesc** s, NimStringDesc* formatstr, NimStringDesc** a, NI aLen0);
N_NOINLINE(void, invalidformatstring_104468)(void);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* dest, NI addlen);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* s, NIM_CHAR c);
N_NIMCALL(NI, findnormalized_104439)(NimStringDesc* x, NimStringDesc** inarray, NI inarrayLen0);
N_NIMCALL(NI, nsuCmpIgnoreStyle)(NimStringDesc* a, NimStringDesc* b);
N_NIMCALL(NIM_CHAR, nsuToLowerChar)(NIM_CHAR c);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI start_81016, NI last);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI first, NI last);
N_NIMCALL(void, preprocesssub_102399)(NimStringDesc* sub, NI* a);
N_NIMCALL(NI, findaux_102467)(NimStringDesc* s, NimStringDesc* sub, NI start, Skiptable102393 a);
N_NIMCALL(NimStringDesc*, nsuNormalize)(NimStringDesc* s);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* s, NI newlen);
static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b);
N_NIMCALL(NI, hashString)(NimStringDesc* s);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
STRING_LITERAL(TMP104, "invalid integer: ", 17);
STRING_LITERAL(TMP132, "invalid format string", 21);
STRING_LITERAL(TMP179, "y", 1);
STRING_LITERAL(TMP180, "yes", 3);
STRING_LITERAL(TMP181, "true", 4);
STRING_LITERAL(TMP182, "1", 1);
STRING_LITERAL(TMP183, "on", 2);
STRING_LITERAL(TMP184, "n", 1);
STRING_LITERAL(TMP185, "no", 2);
STRING_LITERAL(TMP186, "false", 5);
STRING_LITERAL(TMP187, "0", 1);
STRING_LITERAL(TMP188, "off", 3);
STRING_LITERAL(TMP189, "cannot interpret as a bool: ", 28);
extern TNimType NTI25028; /* ref ValueError */
extern TNimType NTI4049; /* ValueError */
extern Gcheap51018 gch_51059;

N_NIMCALL(NIM_BOOL, nsuStartsWith)(NimStringDesc* s, NimStringDesc* prefix) {
	NIM_BOOL result;
	NI i;
{	result = 0;
	i = ((NI) 0);
	{
		while (1) {
			{
				if (!((NU8)(prefix->data[i]) == (NU8)(0))) goto LA5;
				result = NIM_TRUE;
				goto BeforeRet;
			}
			LA5: ;
			{
				if (!!(((NU8)(s->data[i]) == (NU8)(prefix->data[i])))) goto LA9;
				result = NIM_FALSE;
				goto BeforeRet;
			}
			LA9: ;
			i += ((NI) 1);
		}
	}
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, nsuFindChar)(NimStringDesc* s, NIM_CHAR sub, NI start) {
	NI result;
{	result = 0;
	{
		NI i_102624;
		NI HEX3Atmp_102626;
		NI res_102629;
		i_102624 = 0;
		HEX3Atmp_102626 = 0;
		HEX3Atmp_102626 = (NI)((s ? s->Sup.len : 0) - ((NI) 1));
		res_102629 = ((NI) (start));
		{
			while (1) {
				if (!(res_102629 <= HEX3Atmp_102626)) goto LA3;
				i_102624 = res_102629;
				{
					if (!((NU8)(sub) == (NU8)(s->data[i_102624]))) goto LA6;
					result = i_102624;
					goto BeforeRet;
				}
				LA6: ;
				res_102629 += ((NI) 1);
			} LA3: ;
		}
	}
	result = ((NI) -1);
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NIM_CHAR, nsuToLowerChar)(NIM_CHAR c) {
	NIM_CHAR result;
	result = 0;
	{
		if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA3;
		result = ((NIM_CHAR) (((NI) ((NI)(((NI) (((NU8)(c)))) + ((NI) 32))))));
	}
	goto LA1;
	LA3: ;
	{
		result = c;
	}
	LA1: ;
	return result;
}

static N_INLINE(void, appendChar)(NimStringDesc* dest, NIM_CHAR c) {
	(*dest).data[((*dest).Sup.len)- 0] = c;
	(*dest).data[((NI)((*dest).Sup.len + ((NI) 1)))- 0] = 0;
	(*dest).Sup.len += ((NI) 1);
}

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) ((&(*dest).data[((*dest).Sup.len)- 0]))), ((NCSTRING) ((*src).data)), (NI)((*src).Sup.len + ((NI) 1)));
	(*dest).Sup.len += (*src).Sup.len;
}

N_NIMCALL(NimStringDesc*, nsuIntToStr)(NI x, NI minchars) {
	NimStringDesc* result;
	result = 0;
	result = nimIntToStr((x > 0? (x) : -(x)));
	{
		NI i_101062;
		NI HEX3Atmp_101064;
		NI res_101067;
		i_101062 = 0;
		HEX3Atmp_101064 = 0;
		HEX3Atmp_101064 = (NI)(((NI) (minchars)) - (result ? result->Sup.len : 0));
		res_101067 = ((NI) 1);
		{
			while (1) {
				NimStringDesc* LOC4;
				if (!(res_101067 <= HEX3Atmp_101064)) goto LA3;
				i_101062 = res_101067;
				LOC4 = 0;
				LOC4 = rawNewString(result->Sup.len + 1);
appendChar(LOC4, 48);
appendString(LOC4, result);
				result = LOC4;
				res_101067 += ((NI) 1);
			} LA3: ;
		}
	}
	{
		NimStringDesc* LOC9;
		if (!(x < ((NI) 0))) goto LA7;
		LOC9 = 0;
		LOC9 = rawNewString(result->Sup.len + 1);
appendChar(LOC9, 45);
appendString(LOC9, result);
		result = LOC9;
	}
	LA7: ;
	return result;
}

static N_INLINE(Cell48947*, usrtocell_52646)(void* usr) {
	Cell48947* result;
	result = 0;
	result = ((Cell48947*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(Cell48947))))));
	return result;
}

static N_INLINE(void, rtladdzct_54204)(Cell48947* c) {
	addzct_52617((&gch_51059.zct), c);
}

static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	{
		Cell48947* c;
		if (!!((src == NIM_NIL))) goto LA3;
		c = usrtocell_52646(src);
		(*c).refcount += ((NI) 8);
	}
	LA3: ;
	{
		Cell48947* c;
		if (!!(((*dest) == NIM_NIL))) goto LA7;
		c = usrtocell_52646((*dest));
		{
			(*c).refcount -= ((NI) 8);
			if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA11;
			rtladdzct_54204(c);
		}
		LA11: ;
	}
	LA7: ;
	(*dest) = src;
}

N_NIMCALL(NI, nsuParseInt)(NimStringDesc* s) {
	NI result;
	NI L;
	result = 0;
	L = npuParseInt(s, (&result), ((NI) 0));
	{
		NIM_BOOL LOC3;
		Valueerror4049* e_101095;
		NimStringDesc* LOC7;
		LOC3 = 0;
		LOC3 = !((L == (s ? s->Sup.len : 0)));
		if (LOC3) goto LA4;
		LOC3 = (L == ((NI) 0));
		LA4: ;
		if (!LOC3) goto LA5;
		e_101095 = 0;
		e_101095 = (Valueerror4049*) newObj((&NTI25028), sizeof(Valueerror4049));
		(*e_101095).Sup.Sup.m_type = (&NTI4049);
		LOC7 = 0;
		LOC7 = rawNewString(s->Sup.len + 17);
appendString(LOC7, ((NimStringDesc*) &TMP104));
appendString(LOC7, s);
		asgnRefNoCycle((void**) (&(*e_101095).Sup.message), LOC7);
		raiseException((Exception*)e_101095, "ValueError");
	}
	LA5: ;
	return result;
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	Cell48947* c;
	c = usrtocell_52646(p);
	{
		(*c).refcount -= ((NI) 8);
		if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA3;
		rtladdzct_54204(c);
	}
	LA3: ;
}

N_NOINLINE(void, invalidformatstring_104468)(void) {
	Valueerror4049* e_104473;
	NimStringDesc* LOC1;
	e_104473 = 0;
	e_104473 = (Valueerror4049*) newObj((&NTI25028), sizeof(Valueerror4049));
	(*e_104473).Sup.Sup.m_type = (&NTI4049);
	LOC1 = 0;
	LOC1 = (*e_104473).Sup.message; (*e_104473).Sup.message = copyStringRC1(((NimStringDesc*) &TMP132));
	if (LOC1) nimGCunrefNoCycle(LOC1);
	raiseException((Exception*)e_104473, "ValueError");
}

N_NIMCALL(NI, nsuCmpIgnoreStyle)(NimStringDesc* a, NimStringDesc* b) {
	NI result;
	NI i;
	NI j;
	result = 0;
	i = ((NI) 0);
	j = ((NI) 0);
	{
		while (1) {
			NIM_CHAR aa;
			NIM_CHAR bb;
			{
				while (1) {
					if (!((NU8)(a->data[i]) == (NU8)(95))) goto LA4;
					i += ((NI) 1);
				} LA4: ;
			}
			{
				while (1) {
					if (!((NU8)(b->data[j]) == (NU8)(95))) goto LA6;
					j += ((NI) 1);
				} LA6: ;
			}
			aa = nsuToLowerChar(a->data[i]);
			bb = nsuToLowerChar(b->data[j]);
			result = (NI)(((NI) (((NU8)(aa)))) - ((NI) (((NU8)(bb)))));
			{
				NIM_BOOL LOC9;
				LOC9 = 0;
				LOC9 = !((result == ((NI) 0)));
				if (LOC9) goto LA10;
				LOC9 = ((NU8)(aa) == (NU8)(0));
				LA10: ;
				if (!LOC9) goto LA11;
				goto LA1;
			}
			LA11: ;
			i += ((NI) 1);
			j += ((NI) 1);
		}
	} LA1: ;
	return result;
}

N_NIMCALL(NI, findnormalized_104439)(NimStringDesc* x, NimStringDesc** inarray, NI inarrayLen0) {
	NI result;
	NI i;
{	result = 0;
	i = ((NI) 0);
	{
		while (1) {
			if (!(i < (inarrayLen0-1))) goto LA2;
			{
				NI LOC5;
				LOC5 = 0;
				LOC5 = nsuCmpIgnoreStyle(x, inarray[i]);
				if (!(LOC5 == ((NI) 0))) goto LA6;
				result = i;
				goto BeforeRet;
			}
			LA6: ;
			i += ((NI) 2);
		} LA2: ;
	}
	result = ((NI) -1);
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(void, nsuAddf)(NimStringDesc** s, NimStringDesc* formatstr, NimStringDesc** a, NI aLen0) {
	NI i;
	NI num;
	i = ((NI) 0);
	num = ((NI) 0);
	{
		while (1) {
			if (!(i < (formatstr ? formatstr->Sup.len : 0))) goto LA2;
			{
				if (!((NU8)(formatstr->data[i]) == (NU8)(36))) goto LA5;
				switch (((NU8)(formatstr->data[(NI)(i + ((NI) 1))]))) {
				case 35:
				{
					{
						if (!((NU64)((aLen0-1)) < (NU64)(num))) goto LA10;
						invalidformatstring_104468();
					}
					LA10: ;
					(*s) = resizeString((*s), a[num]->Sup.len + 0);
appendString((*s), a[num]);
					i += ((NI) 2);
					num += ((NI) 1);
				}
				break;
				case 36:
				{
					(*s) = addChar((*s), 36);
					i += ((NI) 2);
				}
				break;
				case 49 ... 57:
				case 45:
				{
					NI j;
					NIM_BOOL negative;
					NI idx;
					j = ((NI) 0);
					i += ((NI) 1);
					negative = ((NU8)(formatstr->data[i]) == (NU8)(45));
					{
						if (!negative) goto LA16;
						i += ((NI) 1);
					}
					LA16: ;
					{
						while (1) {
							if (!(((NU8)(formatstr->data[i])) >= ((NU8)(48)) && ((NU8)(formatstr->data[i])) <= ((NU8)(57)))) goto LA19;
							j = (NI)((NI)((NI)(j * ((NI) 10)) + ((NI) (((NU8)(formatstr->data[i]))))) - ((NI) 48));
							i += ((NI) 1);
						} LA19: ;
					}
					{
						if (!!(negative)) goto LA22;
						idx = (NI)(j - ((NI) 1));
					}
					goto LA20;
					LA22: ;
					{
						idx = (NI)(aLen0 - j);
					}
					LA20: ;
					{
						if (!((NU64)((aLen0-1)) < (NU64)(idx))) goto LA27;
						invalidformatstring_104468();
					}
					LA27: ;
					(*s) = resizeString((*s), a[idx]->Sup.len + 0);
appendString((*s), a[idx]);
				}
				break;
				case 123:
				{
					NI j;
					NI x;
					NimStringDesc* LOC32;
					j = (NI)(i + ((NI) 1));
					{
						while (1) {
							if (!!((((NU8)(formatstr->data[j])) == ((NU8)(0)) || ((NU8)(formatstr->data[j])) == ((NU8)(125))))) goto LA31;
							j += ((NI) 1);
						} LA31: ;
					}
					LOC32 = 0;
					LOC32 = copyStrLast(formatstr, (NI)(i + ((NI) 2)), (NI)(j - ((NI) 1)));
					x = findnormalized_104439(LOC32, a, aLen0);
					{
						NIM_BOOL LOC35;
						LOC35 = 0;
						LOC35 = (((NI) 0) <= x);
						if (!(LOC35)) goto LA36;
						LOC35 = (x < (aLen0-1));
						LA36: ;
						if (!LOC35) goto LA37;
						(*s) = resizeString((*s), a[(NI)(x + ((NI) 1))]->Sup.len + 0);
appendString((*s), a[(NI)(x + ((NI) 1))]);
					}
					goto LA33;
					LA37: ;
					{
						invalidformatstring_104468();
					}
					LA33: ;
					i = (NI)(j + ((NI) 1));
				}
				break;
				case 97 ... 122:
				case 65 ... 90:
				case 128 ... 255:
				case 95:
				{
					NI j;
					NI x;
					NimStringDesc* LOC43;
					j = (NI)(i + ((NI) 1));
					{
						while (1) {
							if (!(((NU8)(formatstr->data[j])) >= ((NU8)(97)) && ((NU8)(formatstr->data[j])) <= ((NU8)(122)) || ((NU8)(formatstr->data[j])) >= ((NU8)(65)) && ((NU8)(formatstr->data[j])) <= ((NU8)(90)) || ((NU8)(formatstr->data[j])) >= ((NU8)(48)) && ((NU8)(formatstr->data[j])) <= ((NU8)(57)) || ((NU8)(formatstr->data[j])) >= ((NU8)(128)) && ((NU8)(formatstr->data[j])) <= ((NU8)(255)) || ((NU8)(formatstr->data[j])) == ((NU8)(95)))) goto LA42;
							j += ((NI) 1);
						} LA42: ;
					}
					LOC43 = 0;
					LOC43 = copyStrLast(formatstr, (NI)(i + ((NI) 1)), (NI)(j - ((NI) 1)));
					x = findnormalized_104439(LOC43, a, aLen0);
					{
						NIM_BOOL LOC46;
						LOC46 = 0;
						LOC46 = (((NI) 0) <= x);
						if (!(LOC46)) goto LA47;
						LOC46 = (x < (aLen0-1));
						LA47: ;
						if (!LOC46) goto LA48;
						(*s) = resizeString((*s), a[(NI)(x + ((NI) 1))]->Sup.len + 0);
appendString((*s), a[(NI)(x + ((NI) 1))]);
					}
					goto LA44;
					LA48: ;
					{
						invalidformatstring_104468();
					}
					LA44: ;
					i = j;
				}
				break;
				default:
				{
					invalidformatstring_104468();
				}
				break;
				}
			}
			goto LA3;
			LA5: ;
			{
				(*s) = addChar((*s), formatstr->data[i]);
				i += ((NI) 1);
			}
			LA3: ;
		} LA2: ;
	}
}

N_NIMCALL(NimStringDesc*, nsuFormatOpenArray)(NimStringDesc* formatstr, NimStringDesc** a, NI aLen0) {
	NimStringDesc* result;
	result = 0;
	result = rawNewString(((NI) ((NI)((formatstr ? formatstr->Sup.len : 0) + (NI)((NU64)(aLen0) << (NU64)(((NI) 4)))))));
	nsuAddf((&result), formatstr, a, aLen0);
	return result;
}

N_NIMCALL(void, preprocesssub_102399)(NimStringDesc* sub, NI* a) {
	NI m;
	m = (sub ? sub->Sup.len : 0);
	{
		NI i_102416;
		NI res_102431;
		i_102416 = 0;
		res_102431 = ((NI) 0);
		{
			while (1) {
				if (!(res_102431 <= ((NI) 255))) goto LA3;
				i_102416 = res_102431;
				a[(((NU8)(((NIM_CHAR) (((NI) (i_102416)))))))- 0] = (NI)(m + ((NI) 1));
				res_102431 += ((NI) 1);
			} LA3: ;
		}
	}
	{
		NI i_102427;
		NI HEX3Atmp_102436;
		NI res_102439;
		i_102427 = 0;
		HEX3Atmp_102436 = 0;
		HEX3Atmp_102436 = (NI)(m - ((NI) 1));
		res_102439 = ((NI) 0);
		{
			while (1) {
				if (!(res_102439 <= HEX3Atmp_102436)) goto LA6;
				i_102427 = res_102439;
				a[(((NU8)(sub->data[i_102427])))- 0] = (NI)(m - i_102427);
				res_102439 += ((NI) 1);
			} LA6: ;
		}
	}
}

N_NIMCALL(NI, findaux_102467)(NimStringDesc* s, NimStringDesc* sub, NI start, Skiptable102393 a) {
	NI result;
	NI m;
	NI n;
	NI j;
{	result = 0;
	m = (sub ? sub->Sup.len : 0);
	n = (s ? s->Sup.len : 0);
	j = start;
	{
		while (1) {
			if (!(j <= (NI)(n - m))) goto LA2;
			{
				{
					NI k_102488;
					NI HEX3Atmp_102500;
					NI res_102503;
					k_102488 = 0;
					HEX3Atmp_102500 = 0;
					HEX3Atmp_102500 = (NI)(m - ((NI) 1));
					res_102503 = ((NI) 0);
					{
						while (1) {
							if (!(res_102503 <= HEX3Atmp_102500)) goto LA6;
							k_102488 = res_102503;
							{
								if (!!(((NU8)(sub->data[k_102488]) == (NU8)(s->data[(NI)(k_102488 + j)])))) goto LA9;
								goto LA3;
							}
							LA9: ;
							res_102503 += ((NI) 1);
						} LA6: ;
					}
				}
				result = j;
				goto BeforeRet;
			} LA3: ;
			j += a[(((NU8)(s->data[(NI)(j + m)])))- 0];
		} LA2: ;
	}
	result = ((NI) -1);
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, nsuFindStr)(NimStringDesc* s, NimStringDesc* sub, NI start) {
	NI result;
	Skiptable102393 a;
	result = 0;
	preprocesssub_102399(sub, a);
	result = findaux_102467(s, sub, ((NI) (start)), a);
	return result;
}

N_NIMCALL(NimStringDesc*, nsuStrip)(NimStringDesc* s, NIM_BOOL leading, NIM_BOOL trailing, TY162040 chars) {
	NimStringDesc* result;
	NI first;
	NI last;
	result = 0;
	first = ((NI) 0);
	last = (NI)((s ? s->Sup.len : 0) - ((NI) 1));
	{
		if (!leading) goto LA3;
		{
			while (1) {
				if (!((chars[((NU8)(s->data[first]))/8] &(1<<(((NU8)(s->data[first]))%8)))!=0)) goto LA6;
				first += ((NI) 1);
			} LA6: ;
		}
	}
	LA3: ;
	{
		if (!trailing) goto LA9;
		{
			while (1) {
				NIM_BOOL LOC13;
				LOC13 = 0;
				LOC13 = (((NI) 0) <= last);
				if (!(LOC13)) goto LA14;
				LOC13 = ((chars[((NU8)(s->data[last]))/8] &(1<<(((NU8)(s->data[last]))%8)))!=0);
				LA14: ;
				if (!LOC13) goto LA12;
				last -= ((NI) 1);
			} LA12: ;
		}
	}
	LA9: ;
	result = copyStrLast(s, first, last);
	return result;
}

N_NIMCALL(NimStringDesc*, nsuNormalize)(NimStringDesc* s) {
	NimStringDesc* result;
	NI j;
	result = 0;
	result = mnewString(((NI) ((s ? s->Sup.len : 0))));
	j = ((NI) 0);
	{
		NI i_99727;
		NI HEX3Atmp_99785;
		NI res_99788;
		i_99727 = 0;
		HEX3Atmp_99785 = 0;
		HEX3Atmp_99785 = (NI)((s ? s->Sup.len : 0) - ((NI) 1));
		res_99788 = ((NI) 0);
		{
			while (1) {
				if (!(res_99788 <= HEX3Atmp_99785)) goto LA3;
				i_99727 = res_99788;
				{
					if (!(((NU8)(s->data[i_99727])) >= ((NU8)(65)) && ((NU8)(s->data[i_99727])) <= ((NU8)(90)))) goto LA6;
					result->data[j] = ((NIM_CHAR) (((NI) ((NI)(((NI) (((NU8)(s->data[i_99727])))) + ((NI) 32))))));
					j += ((NI) 1);
				}
				goto LA4;
				LA6: ;
				{
					if (!!(((NU8)(s->data[i_99727]) == (NU8)(95)))) goto LA9;
					result->data[j] = s->data[i_99727];
					j += ((NI) 1);
				}
				goto LA4;
				LA9: ;
				LA4: ;
				res_99788 += ((NI) 1);
			} LA3: ;
		}
	}
	{
		if (!!((j == (s ? s->Sup.len : 0)))) goto LA13;
		result = setLengthStr(result, ((NI) (j)));
	}
	LA13: ;
	return result;
}

static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b) {
	NIM_BOOL result;
	NIM_BOOL LOC11;
	int LOC13;
{	result = 0;
	{
		if (!(a == b)) goto LA3;
		result = NIM_TRUE;
		goto BeforeRet;
	}
	LA3: ;
	{
		NIM_BOOL LOC7;
		LOC7 = 0;
		LOC7 = (a == NIM_NIL);
		if (LOC7) goto LA8;
		LOC7 = (b == NIM_NIL);
		LA8: ;
		if (!LOC7) goto LA9;
		result = NIM_FALSE;
		goto BeforeRet;
	}
	LA9: ;
	LOC11 = 0;
	LOC11 = ((*a).Sup.len == (*b).Sup.len);
	if (!(LOC11)) goto LA12;
	LOC13 = 0;
	LOC13 = memcmp(((NCSTRING) ((*a).data)), ((NCSTRING) ((*b).data)), (*a).Sup.len);
	LOC11 = (LOC13 == ((NI32) 0));
	LA12: ;
	result = LOC11;
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NIM_BOOL, parsebool_101305)(NimStringDesc* s) {
	NIM_BOOL result;
	NimStringDesc* LOC1;
	result = 0;
	LOC1 = 0;
	LOC1 = nsuNormalize(s);
	switch (hashString(LOC1) & 15) {
	case 0: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP180))) goto LA2;
break;
	case 1: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP184))) goto LA3;
break;
	case 5: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP181))) goto LA2;
if (eqStrings(LOC1, ((NimStringDesc*) &TMP185))) goto LA3;
if (eqStrings(LOC1, ((NimStringDesc*) &TMP188))) goto LA3;
break;
	case 8: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP179))) goto LA2;
if (eqStrings(LOC1, ((NimStringDesc*) &TMP183))) goto LA2;
break;
	case 9: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP182))) goto LA2;
break;
	case 10: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP186))) goto LA3;
break;
	case 11: 
if (eqStrings(LOC1, ((NimStringDesc*) &TMP187))) goto LA3;
break;
	}
	goto LA4;
	LA2: ;
	{
		result = NIM_TRUE;
	}
	goto LA5;
	LA3: ;
	{
		result = NIM_FALSE;
	}
	goto LA5;
	LA4: ;
	{
		Valueerror4049* e_101312;
		NimStringDesc* LOC9;
		e_101312 = 0;
		e_101312 = (Valueerror4049*) newObj((&NTI25028), sizeof(Valueerror4049));
		(*e_101312).Sup.Sup.m_type = (&NTI4049);
		LOC9 = 0;
		LOC9 = rawNewString(s->Sup.len + 28);
appendString(LOC9, ((NimStringDesc*) &TMP189));
appendString(LOC9, s);
		asgnRefNoCycle((void**) (&(*e_101312).Sup.message), LOC9);
		raiseException((Exception*)e_101312, "ValueError");
	}
	LA5: ;
	return result;
}

N_NIMCALL(NimStringDesc*, nsuFormatSingleElem)(NimStringDesc* formatstr, NimStringDesc* a) {
	NimStringDesc* result;
	TY168231 LOC1;
	result = 0;
	result = rawNewString(((NI) ((NI)((formatstr ? formatstr->Sup.len : 0) + (a ? a->Sup.len : 0)))));
	memset((void*)LOC1, 0, sizeof(LOC1));
	LOC1[0] = copyString(a);
	nsuAddf((&result), formatstr, LOC1, 1);
	return result;
}
NIM_EXTERNC N_NOINLINE(void, HEX00_strutilsInit000)(void) {
}

NIM_EXTERNC N_NOINLINE(void, HEX00_strutilsDatInit000)(void) {
}
