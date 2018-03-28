#include <MiniCppUnit.hxx>
#include "Item.hxx"

class ItemTest : public TestFixture< ItemTest >
{

public:

    TEST_FIXTURE( ItemTest )
    { 
        TEST_CASE( test_name_byDefault );   
        TEST_CASE( test_level_byDefault );		
	TEST_CASE( test_level_whenChanged );
        TEST_CASE( test_bool_byDefault );
	TEST_CASE( test_bool_withItem );
    }

    void test_name_byDefault()
    {
        Item item1;

        ASSERT_EQUALS( "unknown", item1.getName() );
    }
  
    void test_level_byDefault()
    {
	Item item1;
	ASSERT_EQUALS(
		50u,
		item1.level()
	);
     }

    void test_level_whenChanged()
    {
	Item item1;
	item1.level(50u);
	ASSERT_EQUALS(
		50u,
		item1.level()
	);
    }

    void test_bool_byDefault()
    {
        Item item1;

        ASSERT_EQUALS( false, item1.hasItem() );
    }

    void test_bool_withItem()
    {
        Item item1;
	   item1.hasItem(true);
        ASSERT_EQUALS( true, item1.hasItem() );
    }

};

REGISTER_FIXTURE( ItemTest )
