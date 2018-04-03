//
//  test.cpp
//  Assignement3
//
//  Created by JOHANN on 02/04/2018.
//  Copyright © 2018 JOHANN. All rights reserved.
//

/*
 test.cpp do Unitesting in several way on the functions of Member.h used by our social network.
 here we included the gtest/gtest.h header that allow us to execute Google Tests.
*/
#include "gtest/gtest.h"
#include "Member.h"

// TESTING THE NUM OF FOLLOWERS

TEST(CountOfFollowers, ZERO_Followers) {
    
    Member dana ;
    EXPECT_EQ(0, dana.numFollowers()) ;
}
TEST(CountOfFollowers, NegativeNumbAvoidance) {
    Member dana ,avi;
    avi.unfollow(dana);
    EXPECT_EQ(0, dana.numFollowers()) ;
}

TEST(CountOfFollowers, SeveralFollowers) {
    Member dana , chana , avi ;
    chana.follow(dana);
    avi.follow(dana);
    EXPECT_EQ(2, dana.numFollowers()) ;
}
TEST(CountOfFollowers, DuplicateFollow) {
    Member dana , chana , avi ;
    chana.follow(dana);
    avi.follow(dana);
    chana.follow(dana);
    EXPECT_EQ(2, dana.numFollowers()) ;
}
TEST(CountOfFollowers, DuplicateUnfollow) {
    Member dana , chana;
    chana.follow(dana);
    chana.unfollow(dana);
    chana.unfollow(dana);
    EXPECT_EQ(0, dana.numFollowers()) ;
}
TEST(CountOfFollowers, MemberDestructor) {
    Member dana , chana, avi;
    chana.follow(dana);
    avi.follow(dana);
    chana.~Member(); // chana is out
    EXPECT_EQ(1, dana.numFollowers()) ;
}

// TESTING THE NUM OF FOLLOWING

TEST(CountOfFollowing, ZERO_Following) {
    
    Member dana ;
    EXPECT_EQ(0, dana.numFollowing()) ;
}
TEST(CountOfFollowing, NegativeNumbAvoidance) {
    Member dana ,avi;
    avi.unfollow(dana);
    EXPECT_EQ(0, avi.numFollowing()) ;
}

TEST(CountOfFollowing, SeveralFollowing) {
    Member dana , chana , avi ;
    chana.follow(dana);
    chana.follow(avi);
    EXPECT_EQ(2, chana.numFollowing()) ;
}
TEST(CountOfFollowing, DuplicateFollow) {
    Member dana , chana , avi ;
    chana.follow(dana);
    avi.follow(dana);
    chana.follow(dana); // duplicate follow is passed over
    EXPECT_EQ(2, dana.numFollowers()) ;
}
TEST(CountOfFollowing, DuplicateUnfollow) {
    Member dana , chana;
    chana.follow(dana);
    chana.unfollow(dana);
    chana.unfollow(dana);
    EXPECT_EQ(0, chana.numFollowing()) ;
}
TEST(CountOfFollowing, MemberDestructor) {
    Member dana , chana, avi;
    chana.follow(dana);
    chana.follow(avi);
    dana.~Member(); // chana is out
    EXPECT_EQ(1, chana.numFollowing()) ;
}


// TESTING THE NUM OF FRIEND IN THE SOCIAL NETWORK

TEST(CountOfMembers, No_One) {
    int numofMembers = Member::count();
    EXPECT_EQ(0, numofMembers ) ;
}

TEST(CountOfMembers, SeveralMembers) {
    Member dana , chana, avi;
    int numofMembers = Member::count();
    EXPECT_EQ(3, numofMembers ) ;
}

TEST(CountOfMembers, MemberDestructor) {
    Member dana , chana, avi;
    dana.~Member(); // destructor
    int numofMembers = Member::count();
    EXPECT_EQ(2, numofMembers ) ;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

