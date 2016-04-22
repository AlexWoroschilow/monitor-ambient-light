/* Generated by Nim Compiler v0.12.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -O3 -fno-strict-aliasing  -I/usr/lib/nim -o /home/sensey/Projects/nim-test/nimcache/parsecfg.o /home/sensey/Projects/nim-test/nimcache/parsecfg.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct Cfgparser166214 Cfgparser166214;
typedef struct Baselexer162032 Baselexer162032;
typedef struct TNimObject TNimObject;
typedef struct Streamobj140227 Streamobj140227;
typedef struct Token166212 Token166212;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Cfgevent166208 Cfgevent166208;
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
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  TNimObject  {
TNimType* m_type;
};
typedef NU8 TY162040[32];
struct  Baselexer162032  {
  TNimObject Sup;
NI bufpos;
NCSTRING buf;
NI buflen;
Streamobj140227* input;
NI linenumber;
NI sentinel;
NI linestart;
TY162040 refillchars;
};
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct  Token166212  {
NU8 kind;
NimStringDesc* literal;
};
struct  Cfgparser166214  {
  Baselexer162032 Sup;
Token166212 tok;
NimStringDesc* filename;
};
struct  Cfgevent166208  {
  TNimObject Sup;
NU8 kind;
union{
struct {NimStringDesc* section;
} S2;
struct {NimStringDesc* key;
NimStringDesc* value;
} S3;
struct {NimStringDesc* msg;
} S4;
} kindU;
};
typedef NimStringDesc* TY166883[4];
typedef N_NIMCALL_PTR(void, TY140228) (Streamobj140227* s);
typedef N_NIMCALL_PTR(NIM_BOOL, TY140232) (Streamobj140227* s);
typedef N_NIMCALL_PTR(void, TY140236) (Streamobj140227* s, NI pos);
typedef N_NIMCALL_PTR(NI, TY140241) (Streamobj140227* s);
typedef N_NIMCALL_PTR(NI, TY140245) (Streamobj140227* s, void* buffer, NI buflen);
typedef N_NIMCALL_PTR(NI, TY140251) (Streamobj140227* s, void* buffer, NI buflen);
typedef N_NIMCALL_PTR(void, TY140257) (Streamobj140227* s, void* buffer, NI buflen);
typedef N_NIMCALL_PTR(void, TY140263) (Streamobj140227* s);
struct  Streamobj140227  {
  TNimObject Sup;
TY140228 closeimpl;
TY140232 atendimpl;
TY140236 setpositionimpl;
TY140241 getpositionimpl;
TY140245 readdataimpl;
TY140251 peekdataimpl;
TY140257 writedataimpl;
TY140263 flushimpl;
};
N_NIMCALL(void, open_163635)(Baselexer162032* L, Streamobj140227* input, NI buflen, TY162040 refillchars);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
N_NIMCALL(void, rawgettok_166253)(Cfgparser166214* c, Token166212* tok);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* s, NI newlen);
N_NIMCALL(void, skip_166748)(Cfgparser166214* c);
N_NIMCALL(NI, handlecrlf_166610)(Cfgparser166214* c, NI pos);
N_NIMCALL(NI, handlecr_163007)(Baselexer162032* L, NI pos);
N_NIMCALL(NI, handlelf_163216)(Baselexer162032* L, NI pos);
N_NIMCALL(void, getstring_166622)(Cfgparser166214* c, Token166212* tok, NIM_BOOL rawmode);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* s, NIM_CHAR c);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* dest, NI addlen);
N_NIMCALL(void, getescapedchar_166475)(Cfgparser166214* c, Token166212* tok);
N_NIMCALL(void, handlehexchar_166325)(Cfgparser166214* c, NI* xi);
N_NIMCALL(void, handledecchars_166419)(Cfgparser166214* c, NI* xi);
N_NIMCALL(void, getsymbol_166708)(Cfgparser166214* c, Token166212* tok);
N_NIMCALL(void, getkeyvalpair_166920)(Cfgparser166214* c, NU8 kind, Cfgevent166208* Result);
N_NIMCALL(void, genericReset)(void* dest, TNimType* mt);
N_NIMCALL(NimStringDesc*, npcerrorStr)(Cfgparser166214* c, NimStringDesc* msg);
N_NIMCALL(NimStringDesc*, nsuFormatOpenArray)(NimStringDesc* formatstr, NimStringDesc** a, NI aLen0);
N_NIMCALL(NI, npcgetLine)(Cfgparser166214* c);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI x);
N_NIMCALL(NI, npcgetColumn)(Cfgparser166214* c);
N_NIMCALL(NI, getcolnumber_164008)(Baselexer162032* L, NI pos);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NOINLINE(void, chckNil)(void* p);
N_NIMCALL(void, close_162054)(Baselexer162032* L);
static NIM_CONST TY162040 TMP120 = {
0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;
STRING_LITERAL(TMP121, "", 0);
STRING_LITERAL(TMP122, "=", 1);
STRING_LITERAL(TMP123, "--", 2);
STRING_LITERAL(TMP124, ":", 1);
STRING_LITERAL(TMP125, "\012", 1);
STRING_LITERAL(TMP126, "]", 1);
STRING_LITERAL(TMP127, "[EOF]", 5);
TNimNode* NimDT_166208_kind[6];
STRING_LITERAL(TMP133, "$1($2, $3) Error: $4", 20);
STRING_LITERAL(TMP134, "symbol expected, but found: ", 28);
STRING_LITERAL(TMP135, "\']\' expected, but found: ", 25);
STRING_LITERAL(TMP136, "invalid token: ", 15);
extern TNimType NTI162032; /* BaseLexer */
TNimType NTI166214; /* CfgParser */
TNimType NTI166212; /* Token */
TNimType NTI166210; /* TokKind */
extern TNimType NTI149; /* string */
extern TNimType NTI4011; /* RootObj */
TNimType NTI166208; /* CfgEvent */
TNimType NTI166206; /* CfgEventKind */

N_NIMCALL(NI, handlecrlf_166610)(Cfgparser166214* c, NI pos) {
	NI result;
	result = 0;
	switch (((NU8)((*c).Sup.buf[pos]))) {
	case 13:
	{
		Baselexer162032* LOC2;
		LOC2 = 0;
		LOC2 = &c->Sup;
		result = handlecr_163007(LOC2, pos);
	}
	break;
	case 10:
	{
		Baselexer162032* LOC4;
		LOC4 = 0;
		LOC4 = &c->Sup;
		result = handlelf_163216(LOC4, pos);
	}
	break;
	default:
	{
		result = pos;
	}
	break;
	}
	return result;
}

N_NIMCALL(void, skip_166748)(Cfgparser166214* c) {
	NI pos;
	NCSTRING buf;
	pos = (*c).Sup.bufpos;
	buf = (*c).Sup.buf;
	{
		while (1) {
			switch (((NU8)(buf[pos]))) {
			case 32:
			case 9:
			{
				pos += ((NI) 1);
			}
			break;
			case 35:
			case 59:
			{
				{
					while (1) {
						if (!!((((NU8)(buf[pos])) == ((NU8)(13)) || ((NU8)(buf[pos])) == ((NU8)(10)) || ((NU8)(buf[pos])) == ((NU8)(0))))) goto LA6;
						pos += ((NI) 1);
					} LA6: ;
				}
			}
			break;
			case 13:
			case 10:
			{
				pos = handlecrlf_166610(c, pos);
				buf = (*c).Sup.buf;
			}
			break;
			default:
			{
				goto LA1;
			}
			break;
			}
		}
	} LA1: ;
	(*c).Sup.bufpos = pos;
}

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) ((&(*dest).data[((*dest).Sup.len)- 0]))), ((NCSTRING) ((*src).data)), (NI)((*src).Sup.len + ((NI) 1)));
	(*dest).Sup.len += (*src).Sup.len;
}

N_NIMCALL(void, handlehexchar_166325)(Cfgparser166214* c, NI* xi) {
	switch (((NU8)((*c).Sup.buf[(*c).Sup.bufpos]))) {
	case 48 ... 57:
	{
		(*xi) = (NI)((NI)((NU64)((*xi)) << (NU64)(((NI) 4))) | ((NI) ((NI)(((NI) (((NU8)((*c).Sup.buf[(*c).Sup.bufpos])))) - ((NI) 48)))));
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 97 ... 102:
	{
		(*xi) = (NI)((NI)((NU64)((*xi)) << (NU64)(((NI) 4))) | ((NI) ((NI)(((NI) ((NI)(((NI) (((NU8)((*c).Sup.buf[(*c).Sup.bufpos])))) - ((NI) 97)))) + ((NI) 10)))));
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 65 ... 70:
	{
		(*xi) = (NI)((NI)((NU64)((*xi)) << (NU64)(((NI) 4))) | ((NI) ((NI)(((NI) ((NI)(((NI) (((NU8)((*c).Sup.buf[(*c).Sup.bufpos])))) - ((NI) 65)))) + ((NI) 10)))));
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	default:
	{
	}
	break;
	}
}

N_NIMCALL(void, handledecchars_166419)(Cfgparser166214* c, NI* xi) {
	{
		while (1) {
			if (!(((NU8)((*c).Sup.buf[(*c).Sup.bufpos])) >= ((NU8)(48)) && ((NU8)((*c).Sup.buf[(*c).Sup.bufpos])) <= ((NU8)(57)))) goto LA2;
			(*xi) = (NI)((NI)((*xi) * ((NI) 10)) + ((NI) ((NI)(((NI) (((NU8)((*c).Sup.buf[(*c).Sup.bufpos])))) - ((NI) 48)))));
			(*c).Sup.bufpos += ((NI) 1);
		} LA2: ;
	}
}

N_NIMCALL(void, getescapedchar_166475)(Cfgparser166214* c, Token166212* tok) {
	(*c).Sup.bufpos += ((NI) 1);
	switch (((NU8)((*c).Sup.buf[(*c).Sup.bufpos]))) {
	case 110:
	case 78:
	{
		(*tok).literal = resizeString((*tok).literal, 1);
appendString((*tok).literal, ((NimStringDesc*) &TMP125));
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 114:
	case 82:
	case 99:
	case 67:
	{
		(*tok).literal = addChar((*tok).literal, 13);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 108:
	case 76:
	{
		(*tok).literal = addChar((*tok).literal, 10);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 102:
	case 70:
	{
		(*tok).literal = addChar((*tok).literal, 12);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 101:
	case 69:
	{
		(*tok).literal = addChar((*tok).literal, 27);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 97:
	case 65:
	{
		(*tok).literal = addChar((*tok).literal, 7);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 98:
	case 66:
	{
		(*tok).literal = addChar((*tok).literal, 8);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 118:
	case 86:
	{
		(*tok).literal = addChar((*tok).literal, 11);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 116:
	case 84:
	{
		(*tok).literal = addChar((*tok).literal, 9);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 39:
	case 34:
	{
		(*tok).literal = addChar((*tok).literal, (*c).Sup.buf[(*c).Sup.bufpos]);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 92:
	{
		(*tok).literal = addChar((*tok).literal, 92);
		(*c).Sup.bufpos += ((NI) 1);
	}
	break;
	case 120:
	case 88:
	{
		NI xi;
		(*c).Sup.bufpos += ((NI) 1);
		xi = ((NI) 0);
		handlehexchar_166325(c, (&xi));
		handlehexchar_166325(c, (&xi));
		(*tok).literal = addChar((*tok).literal, ((NIM_CHAR) (((NI) (xi)))));
	}
	break;
	case 48 ... 57:
	{
		NI xi;
		xi = ((NI) 0);
		handledecchars_166419(c, (&xi));
		{
			if (!(xi <= ((NI) 255))) goto LA16;
			(*tok).literal = addChar((*tok).literal, ((NIM_CHAR) (((NI) (xi)))));
		}
		goto LA14;
		LA16: ;
		{
			(*tok).kind = ((NU8) 0);
		}
		LA14: ;
	}
	break;
	default:
	{
		(*tok).kind = ((NU8) 0);
	}
	break;
	}
}

N_NIMCALL(void, getstring_166622)(Cfgparser166214* c, Token166212* tok, NIM_BOOL rawmode) {
	NI pos;
	NCSTRING buf;
	pos = (NI)((*c).Sup.bufpos + ((NI) 1));
	buf = (*c).Sup.buf;
	(*tok).kind = ((NU8) 2);
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = ((NU8)(buf[pos]) == (NU8)(34));
		if (!(LOC3)) goto LA4;
		LOC3 = ((NU8)(buf[(NI)(pos + ((NI) 1))]) == (NU8)(34));
		LA4: ;
		if (!LOC3) goto LA5;
		pos += ((NI) 2);
		pos = handlecrlf_166610(c, pos);
		buf = (*c).Sup.buf;
		{
			while (1) {
				switch (((NU8)(buf[pos]))) {
				case 34:
				{
					{
						NIM_BOOL LOC12;
						LOC12 = 0;
						LOC12 = ((NU8)(buf[(NI)(pos + ((NI) 1))]) == (NU8)(34));
						if (!(LOC12)) goto LA13;
						LOC12 = ((NU8)(buf[(NI)(pos + ((NI) 2))]) == (NU8)(34));
						LA13: ;
						if (!LOC12) goto LA14;
						goto LA7;
					}
					LA14: ;
					(*tok).literal = addChar((*tok).literal, 34);
					pos += ((NI) 1);
				}
				break;
				case 13:
				case 10:
				{
					pos = handlecrlf_166610(c, pos);
					buf = (*c).Sup.buf;
					(*tok).literal = resizeString((*tok).literal, 1);
appendString((*tok).literal, ((NimStringDesc*) &TMP125));
				}
				break;
				case 0:
				{
					(*tok).kind = ((NU8) 0);
					goto LA7;
				}
				break;
				default:
				{
					(*tok).literal = addChar((*tok).literal, buf[pos]);
					pos += ((NI) 1);
				}
				break;
				}
			}
		} LA7: ;
		(*c).Sup.bufpos = (NI)(pos + ((NI) 3));
	}
	goto LA1;
	LA5: ;
	{
		{
			while (1) {
				NIM_CHAR ch;
				ch = buf[pos];
				{
					if (!((NU8)(ch) == (NU8)(34))) goto LA24;
					pos += ((NI) 1);
					goto LA20;
				}
				LA24: ;
				{
					if (!(((NU8)(ch)) == ((NU8)(13)) || ((NU8)(ch)) == ((NU8)(10)) || ((NU8)(ch)) == ((NU8)(0)))) goto LA28;
					(*tok).kind = ((NU8) 0);
					goto LA20;
				}
				LA28: ;
				{
					NIM_BOOL LOC32;
					LOC32 = 0;
					LOC32 = ((NU8)(ch) == (NU8)(92));
					if (!(LOC32)) goto LA33;
					LOC32 = !(rawmode);
					LA33: ;
					if (!LOC32) goto LA34;
					(*c).Sup.bufpos = pos;
					getescapedchar_166475(c, tok);
					pos = (*c).Sup.bufpos;
				}
				goto LA30;
				LA34: ;
				{
					(*tok).literal = addChar((*tok).literal, ch);
					pos += ((NI) 1);
				}
				LA30: ;
			}
		} LA20: ;
		(*c).Sup.bufpos = pos;
	}
	LA1: ;
}

N_NIMCALL(void, getsymbol_166708)(Cfgparser166214* c, Token166212* tok) {
	NI pos;
	NCSTRING buf;
	pos = (*c).Sup.bufpos;
	buf = (*c).Sup.buf;
	{
		while (1) {
			(*tok).literal = addChar((*tok).literal, buf[pos]);
			pos += ((NI) 1);
			{
				if (!!((((NU8)(buf[pos])) >= ((NU8)(97)) && ((NU8)(buf[pos])) <= ((NU8)(122)) || ((NU8)(buf[pos])) >= ((NU8)(65)) && ((NU8)(buf[pos])) <= ((NU8)(90)) || ((NU8)(buf[pos])) >= ((NU8)(48)) && ((NU8)(buf[pos])) <= ((NU8)(57)) || ((NU8)(buf[pos])) == ((NU8)(95)) || ((NU8)(buf[pos])) >= ((NU8)(128)) && ((NU8)(buf[pos])) <= ((NU8)(255)) || ((NU8)(buf[pos])) == ((NU8)(46)) || ((NU8)(buf[pos])) == ((NU8)(47)) || ((NU8)(buf[pos])) == ((NU8)(92))))) goto LA5;
				goto LA1;
			}
			LA5: ;
		}
	} LA1: ;
	(*c).Sup.bufpos = pos;
	(*tok).kind = ((NU8) 2);
}

N_NIMCALL(void, rawgettok_166253)(Cfgparser166214* c, Token166212* tok) {
	(*tok).kind = ((NU8) 0);
	(*tok).literal = setLengthStr((*tok).literal, ((NI) 0));
	skip_166748(c);
	switch (((NU8)((*c).Sup.buf[(*c).Sup.bufpos]))) {
	case 61:
	{
		(*tok).kind = ((NU8) 3);
		(*c).Sup.bufpos += ((NI) 1);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP122)));
	}
	break;
	case 45:
	{
		(*c).Sup.bufpos += ((NI) 1);
		{
			if (!((NU8)((*c).Sup.buf[(*c).Sup.bufpos]) == (NU8)(45))) goto LA5;
			(*c).Sup.bufpos += ((NI) 1);
		}
		LA5: ;
		(*tok).kind = ((NU8) 7);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP123)));
	}
	break;
	case 58:
	{
		(*tok).kind = ((NU8) 4);
		(*c).Sup.bufpos += ((NI) 1);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP124)));
	}
	break;
	case 114:
	case 82:
	{
		{
			if (!((NU8)((*c).Sup.buf[(NI)((*c).Sup.bufpos + ((NI) 1))]) == (NU8)(34))) goto LA11;
			(*c).Sup.bufpos += ((NI) 1);
			getstring_166622(c, tok, NIM_TRUE);
		}
		goto LA9;
		LA11: ;
		{
			getsymbol_166708(c, tok);
		}
		LA9: ;
	}
	break;
	case 91:
	{
		(*tok).kind = ((NU8) 5);
		(*c).Sup.bufpos += ((NI) 1);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP126)));
	}
	break;
	case 93:
	{
		(*tok).kind = ((NU8) 6);
		(*c).Sup.bufpos += ((NI) 1);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP126)));
	}
	break;
	case 34:
	{
		getstring_166622(c, tok, NIM_FALSE);
	}
	break;
	case 0:
	{
		(*tok).kind = ((NU8) 1);
		unsureAsgnRef((void**) (&(*tok).literal), copyString(((NimStringDesc*) &TMP127)));
	}
	break;
	default:
	{
		getsymbol_166708(c, tok);
	}
	break;
	}
}

N_NIMCALL(void, npcopen)(Cfgparser166214* c, Streamobj140227* input, NimStringDesc* filename, NI lineoffset) {
	Baselexer162032* LOC1;
	LOC1 = 0;
	LOC1 = &c->Sup;
	open_163635(LOC1, input, ((NI) 8192), TMP120);
	unsureAsgnRef((void**) (&(*c).filename), copyString(filename));
	(*c).tok.kind = ((NU8) 0);
	unsureAsgnRef((void**) (&(*c).tok.literal), copyString(((NimStringDesc*) &TMP121)));
	(*c).Sup.linenumber += lineoffset;
	rawgettok_166253(c, (&(*c).tok));
}

N_NIMCALL(NI, npcgetLine)(Cfgparser166214* c) {
	NI result;
	result = 0;
	result = (*c).Sup.linenumber;
	return result;
}

N_NIMCALL(NI, npcgetColumn)(Cfgparser166214* c) {
	NI result;
	result = 0;
	result = getcolnumber_164008((&(*c).Sup), (*c).Sup.bufpos);
	return result;
}

N_NIMCALL(NimStringDesc*, npcerrorStr)(Cfgparser166214* c, NimStringDesc* msg) {
	NimStringDesc* result;
	TY166883 LOC1;
	NI LOC2;
	NI LOC3;
	result = 0;
	memset((void*)LOC1, 0, sizeof(LOC1));
	LOC1[0] = copyString((*c).filename);
	LOC2 = 0;
	LOC2 = npcgetLine(c);
	LOC1[1] = nimIntToStr(LOC2);
	LOC3 = 0;
	LOC3 = npcgetColumn(c);
	LOC1[2] = nimIntToStr(LOC3);
	LOC1[3] = copyString(msg);
	result = nsuFormatOpenArray(((NimStringDesc*) &TMP133), LOC1, 4);
	return result;
}

N_NIMCALL(void, getkeyvalpair_166920)(Cfgparser166214* c, NU8 kind, Cfgevent166208* Result) {
	{
		if (!((*c).tok.kind == ((NU8) 2))) goto LA3;
		(*Result).kind = kind;
		unsureAsgnRef((void**) (&(*Result).kindU.S3.key), copyString((*c).tok.literal));
		unsureAsgnRef((void**) (&(*Result).kindU.S3.value), copyString(((NimStringDesc*) &TMP121)));
		rawgettok_166253(c, (&(*c).tok));
		{
			if (!((24 &(1<<(((*c).tok.kind)&7)))!=0)) goto LA7;
			rawgettok_166253(c, (&(*c).tok));
			{
				if (!((*c).tok.kind == ((NU8) 2))) goto LA11;
				unsureAsgnRef((void**) (&(*Result).kindU.S3.value), copyString((*c).tok.literal));
			}
			goto LA9;
			LA11: ;
			{
				NimStringDesc* LOC14;
				genericReset((void*)Result, (&NTI166208));
				(*Result).kind = ((NU8) 4);
				LOC14 = 0;
				LOC14 = rawNewString((*c).tok.literal->Sup.len + 28);
appendString(LOC14, ((NimStringDesc*) &TMP134));
appendString(LOC14, (*c).tok.literal);
				unsureAsgnRef((void**) (&(*Result).kindU.S4.msg), npcerrorStr((&(*c)), LOC14));
			}
			LA9: ;
			rawgettok_166253(c, (&(*c).tok));
		}
		LA7: ;
	}
	goto LA1;
	LA3: ;
	{
		NimStringDesc* LOC16;
		(*Result).kind = ((NU8) 4);
		LOC16 = 0;
		LOC16 = rawNewString((*c).tok.literal->Sup.len + 28);
appendString(LOC16, ((NimStringDesc*) &TMP134));
appendString(LOC16, (*c).tok.literal);
		unsureAsgnRef((void**) (&(*Result).kindU.S4.msg), npcerrorStr((&(*c)), LOC16));
		rawgettok_166253(c, (&(*c).tok));
	}
	LA1: ;
}

N_NIMCALL(void, npcnext)(Cfgparser166214* c, Cfgevent166208* Result) {
	switch ((*c).tok.kind) {
	case ((NU8) 1):
	{
		(*Result).kind = ((NU8) 0);
	}
	break;
	case ((NU8) 7):
	{
		rawgettok_166253(c, (&(*c).tok));
		chckNil((void*)Result);
		genericReset((void*)Result, (&NTI166208));
		(*Result).Sup.m_type = (&NTI166208);
		getkeyvalpair_166920(c, ((NU8) 3), Result);
	}
	break;
	case ((NU8) 2):
	{
		chckNil((void*)Result);
		genericReset((void*)Result, (&NTI166208));
		(*Result).Sup.m_type = (&NTI166208);
		getkeyvalpair_166920(c, ((NU8) 2), Result);
	}
	break;
	case ((NU8) 5):
	{
		rawgettok_166253(c, (&(*c).tok));
		{
			if (!((*c).tok.kind == ((NU8) 2))) goto LA7;
			(*Result).kind = ((NU8) 1);
			unsureAsgnRef((void**) (&(*Result).kindU.S2.section), copyString((*c).tok.literal));
		}
		goto LA5;
		LA7: ;
		{
			NimStringDesc* LOC10;
			(*Result).kind = ((NU8) 4);
			LOC10 = 0;
			LOC10 = rawNewString((*c).tok.literal->Sup.len + 28);
appendString(LOC10, ((NimStringDesc*) &TMP134));
appendString(LOC10, (*c).tok.literal);
			unsureAsgnRef((void**) (&(*Result).kindU.S4.msg), npcerrorStr((&(*c)), LOC10));
		}
		LA5: ;
		rawgettok_166253(c, (&(*c).tok));
		{
			if (!((*c).tok.kind == ((NU8) 6))) goto LA13;
			rawgettok_166253(c, (&(*c).tok));
		}
		goto LA11;
		LA13: ;
		{
			NimStringDesc* LOC16;
			genericReset((void*)Result, (&NTI166208));
			(*Result).kind = ((NU8) 4);
			LOC16 = 0;
			LOC16 = rawNewString((*c).tok.literal->Sup.len + 25);
appendString(LOC16, ((NimStringDesc*) &TMP135));
appendString(LOC16, (*c).tok.literal);
			unsureAsgnRef((void**) (&(*Result).kindU.S4.msg), npcerrorStr((&(*c)), LOC16));
		}
		LA11: ;
	}
	break;
	case ((NU8) 0):
	case ((NU8) 3):
	case ((NU8) 4):
	case ((NU8) 6):
	{
		NimStringDesc* LOC18;
		(*Result).kind = ((NU8) 4);
		LOC18 = 0;
		LOC18 = rawNewString((*c).tok.literal->Sup.len + 15);
appendString(LOC18, ((NimStringDesc*) &TMP136));
appendString(LOC18, (*c).tok.literal);
		unsureAsgnRef((void**) (&(*Result).kindU.S4.msg), npcerrorStr((&(*c)), LOC18));
		rawgettok_166253(c, (&(*c).tok));
	}
	break;
	}
}

N_NIMCALL(void, npcclose)(Cfgparser166214* c) {
	Baselexer162032* LOC1;
	LOC1 = 0;
	LOC1 = &c->Sup;
	close_162054(LOC1);
}
NIM_EXTERNC N_NOINLINE(void, HEX00_parsecfgInit000)(void) {
}

NIM_EXTERNC N_NOINLINE(void, HEX00_parsecfgDatInit000)(void) {
static TNimNode* TMP115[2];
static TNimNode* TMP116[2];
static TNimNode* TMP117[8];
NI TMP119;
static char* NIM_CONST TMP118[8] = {
"tkInvalid", 
"tkEof", 
"tkSymbol", 
"tkEquals", 
"tkColon", 
"tkBracketLe", 
"tkBracketRi", 
"tkDashDash"};
static TNimNode* TMP128[5];
NI TMP130;
static char* NIM_CONST TMP129[5] = {
"cfgEof", 
"cfgSectionStart", 
"cfgKeyValuePair", 
"cfgOption", 
"cfgError"};
static TNimNode* TMP131[2];
static TNimNode TMP37[28];
NTI166214.size = sizeof(Cfgparser166214);
NTI166214.kind = 17;
NTI166214.base = (&NTI162032);
TMP115[0] = &TMP37[1];
NTI166212.size = sizeof(Token166212);
NTI166212.kind = 18;
NTI166212.base = 0;
NTI166212.flags = 2;
TMP116[0] = &TMP37[3];
NTI166210.size = sizeof(NU8);
NTI166210.kind = 14;
NTI166210.base = 0;
NTI166210.flags = 3;
for (TMP119 = 0; TMP119 < 8; TMP119++) {
TMP37[TMP119+4].kind = 1;
TMP37[TMP119+4].offset = TMP119;
TMP37[TMP119+4].name = TMP118[TMP119];
TMP117[TMP119] = &TMP37[TMP119+4];
}
TMP37[12].len = 8; TMP37[12].kind = 2; TMP37[12].sons = &TMP117[0];
NTI166210.node = &TMP37[12];
TMP37[3].kind = 1;
TMP37[3].offset = offsetof(Token166212, kind);
TMP37[3].typ = (&NTI166210);
TMP37[3].name = "kind";
TMP116[1] = &TMP37[13];
TMP37[13].kind = 1;
TMP37[13].offset = offsetof(Token166212, literal);
TMP37[13].typ = (&NTI149);
TMP37[13].name = "literal";
TMP37[2].len = 2; TMP37[2].kind = 2; TMP37[2].sons = &TMP116[0];
NTI166212.node = &TMP37[2];
TMP37[1].kind = 1;
TMP37[1].offset = offsetof(Cfgparser166214, tok);
TMP37[1].typ = (&NTI166212);
TMP37[1].name = "tok";
TMP115[1] = &TMP37[14];
TMP37[14].kind = 1;
TMP37[14].offset = offsetof(Cfgparser166214, filename);
TMP37[14].typ = (&NTI149);
TMP37[14].name = "filename";
TMP37[0].len = 2; TMP37[0].kind = 2; TMP37[0].sons = &TMP115[0];
NTI166214.node = &TMP37[0];
NTI166208.size = sizeof(Cfgevent166208);
NTI166208.kind = 17;
NTI166208.base = (&NTI4011);
NTI166206.size = sizeof(NU8);
NTI166206.kind = 14;
NTI166206.base = 0;
NTI166206.flags = 3;
for (TMP130 = 0; TMP130 < 5; TMP130++) {
TMP37[TMP130+16].kind = 1;
TMP37[TMP130+16].offset = TMP130;
TMP37[TMP130+16].name = TMP129[TMP130];
TMP128[TMP130] = &TMP37[TMP130+16];
}
TMP37[21].len = 5; TMP37[21].kind = 2; TMP37[21].sons = &TMP128[0];
NTI166206.node = &TMP37[21];
TMP37[15].kind = 3;
TMP37[15].offset = offsetof(Cfgevent166208, kind);
TMP37[15].typ = (&NTI166206);
TMP37[15].name = "kind";
TMP37[15].sons = &NimDT_166208_kind[0];
TMP37[15].len = 5;
TMP37[22].len = 0; TMP37[22].kind = 2;
NimDT_166208_kind[0] = &TMP37[22];
TMP37[23].kind = 1;
TMP37[23].offset = offsetof(Cfgevent166208, kindU.S2.section);
TMP37[23].typ = (&NTI149);
TMP37[23].name = "section";
NimDT_166208_kind[1] = &TMP37[23];
TMP131[0] = &TMP37[25];
TMP37[25].kind = 1;
TMP37[25].offset = offsetof(Cfgevent166208, kindU.S3.key);
TMP37[25].typ = (&NTI149);
TMP37[25].name = "key";
TMP131[1] = &TMP37[26];
TMP37[26].kind = 1;
TMP37[26].offset = offsetof(Cfgevent166208, kindU.S3.value);
TMP37[26].typ = (&NTI149);
TMP37[26].name = "value";
TMP37[24].len = 2; TMP37[24].kind = 2; TMP37[24].sons = &TMP131[0];
NimDT_166208_kind[2] = &TMP37[24];
NimDT_166208_kind[3] = &TMP37[24];
TMP37[27].kind = 1;
TMP37[27].offset = offsetof(Cfgevent166208, kindU.S4.msg);
TMP37[27].typ = (&NTI149);
TMP37[27].name = "msg";
NimDT_166208_kind[4] = &TMP37[27];
NTI166208.node = &TMP37[15];
}
