/**
 * \brief  Implementation of the \class Member.
 * A Member is able to follow and unfollow another member.
 * \author Johann and Samuel.
 */

/** Include of the file Member.h". */
#include "Member.h"

/** We use a static counter to count the number of user(s) to make easier the manipulation with the members. */
static int id_Member = 0;
static int number_of_member = 0; //The number of user(s).

/**
 * \brief Constructor to control all the new members.
 *  As said in the Member.h file, there is no need to worried about the duplicate follow.
 */
Member::Member() {
    this->id = id_Member++;
    number_of_member++;
}

/**
 * \brief Destructor to control all the delete members.
 * One of the issues (when we still use vector) was in the use of the destructor : we saw that the destructor was called numerous times,
 * and this without our control.
 * since we use map, this problem have been resolve.
 * Here we need also to worried about all the data that the destructed object let, and delete it.
 */
Member::~Member() {
    number_of_member--;
    map<int, Member*>::iterator it;
    for(it = mapFollowings.begin(); it != mapFollowings.end(); ++it)
		it->second->mapFollowers.erase(it->second->mapFollowers.find(this->id));
	for(it = mapFollowers.begin(); it != mapFollowers.end(); ++it)
		it->second->mapFollowings.erase(it->second->mapFollowings.find(this->id));
}

/**
 * \param member.
 * \brief this method do a "follow" between from the "this" to the member.
 */
void Member::follow(Member &member) {
    if(&member != this){
        if(mapFollowings.count(member.id) == 0) { //if the member is not follow.
            mapFollowings[member.id] = &member;
            member.mapFollowers[this->id] = this;
        }
    }
}

/**
 * \param member.
 * \brief this method do a "unfollow" between from the "this" to the member.
 */
void Member::unfollow(Member &member) {
    if(&member != this){
        if(this->mapFollowings.count(member.id) == 1) { //if the member if follow.
            this->mapFollowings.erase(member.id);
            member.mapFollowers.erase(this->id);
        }
    }
}

/**
 * \return the number of user of the social network.
 */
int Member::count() {
   return number_of_member;
}

/** Something important here is the complexity of the method size().
 * by http://www.cplusplus.com/reference/map/map/size/ the size is found in a constant time.
 * The question is how much cost the memory of the size of the map.
 * And this may us asking if the time complexity is more important that the size or not ?
 */

/**
 * \return the number of follower of the "this" member.
 */
int Member::numFollowers() {
    return mapFollowers.size();
}

/**
 * \return the number of following of the "this" member.
 */
int Member::numFollowing() {
    return mapFollowings.size();
}
