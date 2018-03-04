#include "Character.hxx"

void Character::locateAt( Location & location)
{
	if( _location) _location->unplaceCharacter( *this );
	location.placeCharacter ( *this );
	_location = &location;
}