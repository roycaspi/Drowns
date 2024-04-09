#include "Area.h"

Area& Area::operator++() {
	drownum = drownum + 1;
	return *this;
}

const Area Area::operator++(int)
{
	Area temp = *this;
	drownum = drownum + 1;
	return temp;
}

Area& Area::operator -- () {
	drownum = drownum - 1;
	return *this;
}

const Area Area::operator -- (int)
{
	Area temp = *this;
	drownum = drownum - 1;
	return temp;
}
