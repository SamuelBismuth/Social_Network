/**
 * \brief  Implementation of the \class Member.
 * A Member is able to follow and unfollow another member.
 * \author Johann and Samuel.
 */

/** Include of the file Member.h". */
#include "Member.h"

/** We use a static counter to count the number of user(s) for one reason : the complexity.
 * Another solution would be to return the size of the array but there are two problems :
 * which is more important : complexity or memory ??
 * And so, the members declared as global are not in the list ?
 */
static int numberOfUsers = 0;
static int id_number = 0;

/** A static vector which contains all the user of the social network. */
vector<Member*> Member::listUsers;

/**
 * \brief Constructor to control all the new members.
 *  Since the duplicate follow has no effect, we check \if the follow is a new one or not.
 */
Member::Member() {
    if(!containsUser(this)) {
        this->id = id_number++;
        this->followers = 0;
        this->followings = 0;
        this->listFollowers = {};
        this->listFollowings = {};
        listUsers.push_back(this);
        numberOfUsers++;
    }
}

/**
 * \brief Destructor to control all the delete members.
 * One of the issues was in the use of the destructor : we saw that the destructor was called numerous times, and this without our control.
 * So we're now checking \if the user is in the list or not.
 * Here we need also to worried about all the data that the destructed object let, and delete it.
 */
Member::~Member() {
    if(containsUser(this)) {
        listUsers.erase(remove(listUsers.begin(), listUsers.end(), this), listUsers.end());
        numberOfUsers--;
        //we need to check here !!!
        for(int i = 0; numberOfUsers; ++i) {
            printf("finitooo %d", listUsers[i]->listFollowers.erase(remove(listFollowers.begin(), listFollowers.end(), this->id), listFollowers.end()));
            listUsers[i]->listFollowings.erase(remove(listFollowings.begin(), listFollowings.end(), this->id), listFollowings.end());
        }
    }
}

/**
 * \param member.
 * \brief this method do a "follow" between from the "this" to the member.
 */
void Member::follow(Member &member) {
    if(!this->containsFollowing(member.id)) {
        followings++;
        listFollowings.push_back(member.id);
        //We need to make test but it's possible that it's work.
        member.followers++;
        member.listFollowers.push_back(this->id);
        //to here
    }
}

/**
 * \param member.
 * \brief this method do a "unfollow" between from the "this" to the member.
 */
void Member::unfollow(Member &member) {
    if(this->containsFollowing(member.id)) {
        followings--;
        listFollowings.erase(remove(listFollowings.begin(), listFollowings.end(), member.id), listFollowings.end());
        //We need to make test but it's possible that it's work.
        member.followers--;
        member.listFollowers.erase(remove(listFollowings.begin(), listFollowings.end(), this->id), listFollowings.end());
        //to here
    }
}

/**
 * \return the number of user of the social network.
 * complexity : O(1) instead of O(n).
 */
int Member::count() {
    return numberOfUsers;
}

/**
 * \return the number of follower of the "this" member.
 * complexity : O(1) instead of O(n).
 */
int Member::numFollowers() {
    return followers;
}

/**
 * \return the number of following of the "this" member.
 * complexity : O(1) instead of O(n).
 */
int Member::numFollowing() {
    return followings;
}

/**
 * \param Member *user.
 * \return true \if the parameter is one of the user of the social network else return false.
 */
bool Member::containsUser(Member *user) {
    return find(listUsers.begin(), listUsers.end(), user) != listUsers.end();
}

/**
 * \param Member following.
 * \return true \if the parameter is one of the following of the "this" member.
 */
bool Member::containsFollowing(int id) {
    return find(this->listFollowings.begin(), this->listFollowings.end(), id) != this->listFollowings.end();
}

/**
 * \param Member first and second.
 * \return true if there are equal, false if they don't.
 * \brief This method define the use of the operator "==".
 */
bool operator== (const Member &first, const Member &second) {
    return first.followers == second.followers;
}
