#include "Location.hxx"

// Extendemos de class Character
void Character::locateAt (Location & location)
{
	if (_location == NULL) { location.placeCharacter(*this); }
	else 
	{
		_location->unplaceCharacter(*this); // El anterior
		location.placeCharacter(*this); // El nuevo
	}
	// Paso clave para guardar el puntero de la localizacion
	_location = &location;
}