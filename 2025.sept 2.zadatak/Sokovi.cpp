#include "Sokovi.h"

Sokovi::Sokovi()
{
	ukus = nullptr;
	procenat = 0;
	zapremina = 0.0f;
}

Sokovi::Sokovi(const char* ukus, float zapremina, int procenat)
{
	this->ukus = new char[strlen(ukus) + 1];
	strcpy(this->ukus, ukus);
	this->zapremina = zapremina;
	this->procenat = procenat;
}

Sokovi::~Sokovi()
{
	if (ukus != nullptr)
	{
		delete[] ukus;
	}
}

Sokovi::Sokovi(const Sokovi& s)
{
	this->ukus = new char[strlen(s.vratiUkus()) + 1];
	strcpy(this->ukus, s.vratiUkus());
	this->zapremina = s.vratiZap();
	this->procenat = s.vratiProc();
}

Sokovi& Sokovi::operator=(const Sokovi& s)
{
	if (this != &s)
	{
		this->ukus = new char[strlen(s.vratiUkus()) + 1];
		strcpy(this->ukus, s.vratiUkus());
		this->zapremina = s.vratiZap();
		this->procenat = s.vratiProc();
	}
	return *this;
}

bool Sokovi::operator<(const Sokovi& s)
{
	if (vratiZap() < s.vratiZap())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Sokovi::operator>(const Sokovi& s)
{
	if (vratiZap() > s.vratiZap())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Sokovi::operator==(const Sokovi& s)
{
	if (vratiZap() == s.vratiZap() &&  strcmp(vratiUkus(),s.vratiUkus())==0 && vratiProc()==s.vratiProc())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Sokovi::operator!=(const Sokovi& s)
{
	if (vratiZap() != s.vratiZap())
	{
		return true;
	}
	else
	{
		return false;
	}
}
