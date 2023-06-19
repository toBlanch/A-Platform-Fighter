#include "Surface.h"
#include <cassert>

void Surface::PutPixel( int x,int y,Color c )
{
	pixels.data()[y * width + x] = c;
}

Color Surface::GetPixel( int x,int y ) const
{
	return pixels.data()[y * width + x];
}

void Surface::Fill( Color c )
{
	std::fill( pixels.begin(),pixels.begin() + height * width,c );
}