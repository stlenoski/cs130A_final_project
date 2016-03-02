#ifndef RANGQUERY_H
#define RANGEQUERY_H


struct User{
	char name[20];
	int index;
};

class RangeQuery{
	public:
		RangeQuery();
		RangeQuery(User u);
		~RangeQuery();
		void insert(User u);
		void listInfo(char* lowerBound, char* upperBound);
		void printAll();
		void listFriendsInfo(char* u);

	private:
		

};

#endif
