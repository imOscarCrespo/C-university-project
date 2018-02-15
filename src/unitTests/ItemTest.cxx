/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#include <MiniCppUnit.hxx>
#include "Item.hxx"

class ItemTest : public TestFixture <ItemTest>
{

public:

	//Declaració dels testos
	TEST_FIXTURE(ItemTest){
	
	TEST_CASE( test_name_byDefault );
	//TEST_CASE( test_name_whenChanged );
	//TEST_CASE( test_level_byDefault );
	//TEST_CASE( test_level_whenChanged );
	//TEST_CASE( test_enable_byDefault );
	//TEST_CASE( test_enable_whenChanged );

	}

	//Definició de cada una dels testos
	void test_name_byDefault()
	{
		Item anonymous;
		ASSERT_EQUALS(
			"unknown",
			anonymous.name()
		);
	}
	/*
	void test_name_whenChanged()
	{
		Item anonymous;
		anonymous.name( "A Item" );
		ASSERT_EQUALS(
			"A Item",
			anonymous.name()
		);
	}

	void test_level_byDefault()
	{
		Item anonymous;
		ASSERT_EQUALS(
			10u,
			anonymous.level()
		);
	}

	void test_level_whenChanged()
	{
		Item anonymous;
		anonymous.level( 40 );
		ASSERT_EQUALS(
			40u,
			anonymous.level()
		);
	}

	void test_enable_byDefault()
	{
		Item anonymous;
		
		ASSERT_EQUALS( 
			false,
			anonymous.enable()
		);

	}

    void test_enable_whenChanged()
    {
			Item anonymous;
			anonymous.enable(true);
        	ASSERT_EQUALS( true, anonymous.enable() );
    }
	

	*/


};

REGISTER_FIXTURE( ItemTest )
