#include "LekcijaNormalna.h"

LekcijaNormalna::LekcijaNormalna()
{
	naziv = nullptr;
	duzina = 0;
	procTezina = 0;
}

bool LekcijaNormalna::operator<(const LekcijaNormalna& l)
{
	if (vratiTezinu() < l.vratiTezinu())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool LekcijaNormalna::operator>(const LekcijaNormalna& l)
{

	if (vratiTezinu() > l.vratiTezinu())
	{
		return true;
	}
	else
	{
		return false;
	}
}
