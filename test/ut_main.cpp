#include <gtest/gtest.h>
#include "ut_fs.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}

TEST(first, first) {
  ASSERT_EQ(2,1+1);
}
