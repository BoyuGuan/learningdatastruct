/*
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdint>

constexpr int MAX_OBJECT_ARRAY_LENGTH = 512;
constexpr int OPE_ADD = 0;
constexpr int OPE_SUB = 1;
constexpr int OPE_MUL = 2;
constexpr int OPE_DIV = 3;
constexpr int OPE_POW = 4;

constexpr int NICE_ADD = 0;
constexpr int NICE_SUB = 0;
constexpr int NICE_MUL = 1;
constexpr int NICE_DIV = 1;
constexpr int NICE_POW = 2;

constexpr int EXTNICE_BKT = 3;

struct TCollectStatus {
	TCollectStatus()
	{
		IfIllegal = IfAfterDot = 0;
		Data = 0;
	}
	bool IfIllegal;
	int IfAfterDot;
	double Data;
};

struct TObject {
	TObject()
	{
		IfEnd = 0;
	}
	bool IfOpe;
	bool IfEnd;
	union {
		double Data_Num;
		struct {
			int Data_Ope;
			int Nice;
		};
	};
};

typedef TObject* lpObject;

inline bool IfNum(char _this)
{
	if (_this == '.')
		return 1;
	else if (_this >= '0' && _this <= '9')
		return 1;
	return 0;
}

inline TCollectStatus MakeIllegal(TCollectStatus _status)
{
	TCollectStatus temp = _status;
	temp.IfIllegal = 1;
	return temp;
}

inline TCollectStatus MakeDot(TCollectStatus _status)
{
	TCollectStatus temp = _status;
	temp.IfAfterDot = 1;
	return temp;
}

inline TCollectStatus UpdateDataBeforeDot(TCollectStatus _status, char _this)
{
	TCollectStatus temp = _status;
	temp.Data = temp.Data * 10 + (_this - '0');
	return temp;
}

inline TCollectStatus UpdateDataAfterDot(TCollectStatus _status, char _this)
{
	TCollectStatus temp = _status;
	temp.Data += (_this - '0') / pow(10, temp.IfAfterDot++);
	return temp;
}

TCollectStatus CollectNum(TCollectStatus _status, char _this)
{
	if (_status.IfIllegal)
		return _status;
	else
		if (_this == '.')
			if (_status.IfAfterDot)
				return MakeIllegal(_status);
			else
				return MakeDot(_status);
		else if (IfNum(_this))
			if (_status.IfAfterDot)
				return UpdateDataAfterDot(_status, _this);
			else
				return UpdateDataBeforeDot(_status, _this);
		else
			return MakeIllegal(_status);
};

lpObject TranslateString(const char* _expr)
{
	lpObject objArrBase = new TObject[MAX_OBJECT_ARRAY_LENGTH];
	lpObject ptrArr = objArrBase;
	int BktCount = 0;
	bool flag = 1;  //num
	TCollectStatus temp;
	int tempOpe = -1;
	int tempNice;

	for (auto p = _expr; *p; p++)
	{
		if (*p == ' ')
			continue;
		else if (*p == '(')
			BktCount++;
		else if (*p == ')')
		{
			if (--BktCount < 0)
				return nullptr;
		}
		else if (IfNum(*p))
			if (flag)
				temp = CollectNum(temp, *p);
			else
			{
				flag = 1;
				ptrArr->IfOpe = 1;
				ptrArr->Data_Ope = tempOpe;
				ptrArr->Nice = tempNice;
				tempOpe = -1;
				ptrArr++;
				temp = CollectNum(temp, *p);
			}
		else
		{
			if (flag)
			{
				if (temp.IfIllegal)
					return nullptr;
				ptrArr->IfOpe = 0;
				ptrArr->Data_Num = temp.Data;
				ptrArr++;
				temp = TCollectStatus();
			}
			flag = 0;
			if (tempOpe != -1)
				return nullptr;
			else switch (*p)
			{
			case '+':
				tempOpe = OPE_ADD;
				tempNice = NICE_ADD + BktCount * EXTNICE_BKT;
				break;
			case '-':
				tempOpe = OPE_SUB;
				tempNice = NICE_SUB + BktCount * EXTNICE_BKT;
				break;
			case '*':
				tempOpe = OPE_MUL;
				tempNice = NICE_MUL + BktCount * EXTNICE_BKT;
				break;
			case '/':
				tempOpe = OPE_DIV;
				tempNice = NICE_DIV + BktCount * EXTNICE_BKT;
				break;
			case '^':
				tempOpe = OPE_POW;
				tempNice = NICE_POW + BktCount * EXTNICE_BKT;
				break;
			default:
				return nullptr;
			}
		}
	}

	if (flag)
	{
		if (temp.IfIllegal)
			return nullptr;
		ptrArr->IfOpe = 0;
		ptrArr->Data_Num = temp.Data;
		ptrArr++;
		temp = TCollectStatus();
	}
	else
	{
		flag = 1;
		ptrArr->IfOpe = 1;
		ptrArr->Data_Ope = tempOpe;
		ptrArr->Nice = tempNice;
		tempOpe = -1;
		ptrArr++;
	}
	ptrArr->IfEnd = 1;
	ptrArr->IfOpe = 1;
	ptrArr->Nice = -1;
	return objArrBase;
}

inline double SubEval(double _fst, double _snd, int _ope)
{
	switch (_ope)
	{
	case OPE_ADD:
		return _fst + _snd;
	case OPE_SUB:
		return _fst - _snd;
	case OPE_MUL:
		return _fst * _snd;
	case OPE_DIV:
		return _fst / _snd;
	case OPE_POW:
		return pow(_fst, _snd);
	}
}

int Eval(lpObject _arr, double* _ret)
{
	if (_arr->IfOpe)
		return -1;
	if (!((_arr + 1)->IfOpe))
		return -1;
	if ((_arr + 1)->IfEnd)
	{
		*_ret = _arr->Data_Num;
		return 0;
	}
	else
	{
		if ((_arr + 2)->IfOpe)
			return -1;
		if (!((_arr + 3)->IfOpe))
			return -1;
		if ((_arr + 1)->Nice >= (_arr + 3)->Nice)
		{
			(_arr + 2)->Data_Num = SubEval(_arr->Data_Num, (_arr + 2)->Data_Num, (_arr + 1)->Data_Ope);
			double temp;
			if (Eval(_arr + 2, &temp))
				return -1;
			else
				*_ret = temp;
		}
		else
		{
			double temp;
			if (Eval(_arr + 2, &temp))
				return -1;
			else
				*_ret = SubEval(_arr->Data_Num, temp, (_arr + 1)->Data_Ope);
		}
		return 0;
	}
}

int main()
{
	//auto s = "1 + 2 * 3";
	auto s = "50*50";
	auto k = TranslateString(s);
	double temp;
	int tret = Eval(k, &temp);
	printf("%d %lf\n", tret, temp);
	//ifnobug answer
}


*/