#pragma once
class Contact
{
protected:
	const char* nume;
public:
	virtual const char* GetName()
	{
		return nume;
	}
};