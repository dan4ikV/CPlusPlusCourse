#pragma once
#define DEF_TAB_SIZE 10

using namespace std;

class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(CTab&& cOther) {
		pi_tab = cOther.pi_tab;
		i_size = cOther.i_size;
		cOther.pi_tab = NULL;
		std::cout << "MOVE ";
	};
	bool bSetSize(int iNewSize);
	int iGetSize() { return(i_size); }
	CTab(const CTab& cOther)
	{
		v_copy(cOther);
		cout << "Copy ";
	}//CTab::CTab(const CTab &cOther)
	~CTab()
	{
		if (pi_tab != NULL) delete pi_tab;
		cout << "Destr ";
	}//CTab::~CTab()
	CTab operator=(const CTab& cOther)
	{
		if (pi_tab != NULL) delete pi_tab;
		v_copy(cOther);
		cout << "op= ";
		return(*this);
	}//CTab CTab::operator=(const CTab &cOther)
	CTab operator=(CTab&& cOther) {
		this->~CTab();
		pi_tab = cOther.pi_tab;
		i_size = cOther.i_size;
		cOther.pi_tab = NULL;
		return *this;
	}
private:
	void v_copy(const CTab& cOther)
	{
		pi_tab = new int[cOther.i_size];
		i_size = cOther.i_size;
		for (int ii = 0; ii < cOther.i_size; ii++)
			pi_tab[ii] = cOther.pi_tab[ii];
	}
	int* pi_tab;
	int i_size;
};