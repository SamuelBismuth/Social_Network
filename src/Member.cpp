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

/** A static vector which contains all the user of the social network. */
vector<Member*> Member::listUsers;


/**
 * \brief Constructor to control all the new members.
 *  Since the duplicate follow has no effect, we check \if the follow is a new one or not.
 */
Member::Member() {
    if(!containsUser(this)) {
        listUsers.push_back(this);
        numberOfUsers++;
    }
}

/**
 * \brief Destructor to control all the delete members.
 * One of the issues was in the use of the destructor : we saw that the destructor was called numerous times, and this without our control.
 * So we're now checking \if the user is in the list or not.
 */
Member::~Member() {
    if(containsUser(this)) {
        listUsers.erase(remove(listUsers.begin(), listUsers.end(), this), listUsers.end());
        numberOfUsers--;
    }
}

/**
 * \param member.
 * \brief this method do a "follow" between from the "this" to the member.
 * We have an issue here which is that when we want to bring some modifications to the member (as a parameter) anything happen.
 */
void Member::follow(Member member) {
    if(!containsFollowing(member)) {
        followings++;
        listFollowings.push_back(member);
        //from here we have an issue
        member.followers++;
        member.listFollowers.push_back(*this);
        //to here
    }
}

/**
 * \param member.
 * \brief this method do a "unfollow" between from the "this" to the member.
 * We have an issue here which is that when we want to bring some modifications to the member (as a parameter) anything happen.
 */
void Member::unfollow(Member member) {
    if(containsFollowing(member)) {
        followings--;
        listFollowings.erase(remove(listFollowings.begin(), listFollowings.end(), member), listFollowings.end());
        //from here we have an issue
        member.followers--;
        member.listFollowers.erase(remove(listFollowings.begin(), listFollowings.end(), *this), listFollowings.end());
        //to here
    }
}

/**
 * \return the number of user of the social network.
 */
int Member::count() {
    return numberOfUsers;
}

/**
 * \return the number of follower of the "this" member.
 */
int Member::numFollowers() {
    return followers;
}

/**
 * \return the number of following of the "this" member.
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
bool Member::containsFollowing(Member following) {
    return find(listFollowings.begin(), listFollowings.end(), following) != listFollowings.end();
}

/**
 * \param Member first and second.
 * \return true if there are equal, false if they don't.
 * \brief This method define the use of the operator "==".
 */
bool operator== (const Member &first, const Member &second) {
    return first.followers == second.followers;
}
