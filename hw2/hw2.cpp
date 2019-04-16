// Array-based List Class for Playlists
// Max Luttrell CS 110C
//
// Hendrik Brutsaert
//
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
	static const int CHUNK_SIZE = 2;
	ItemType *list;
	int numItems;
	int maxItems;
public:
	// default constructor and destructor
	List() {
		numItems = 0; maxItems = CHUNK_SIZE;
		list = new ItemType[CHUNK_SIZE];
	}
	~List() { delete[] list; }

	// list member functions
	bool isEmpty()  const { return numItems == 0; }
	int getLength() const { return numItems; }
	bool insert(int pos, const ItemType& item);
	bool remove(int pos);

	// clear the list
	// clear can simply set numItems to zero.  The array list may still contain
	// items already inserted into the list, but since numItems is zero, there
	// isn't any way to get at them using getEntry() or setEntry()
	void clear() { numItems = 0; }

	// return entry at postion pos
	// throw invalid_argument if pos<1 or pos>getLength()
	ItemType getEntry(int pos) const;

	// set entry at postion pos to item
	// throw invalid_argument if pos<1 or pos>getLength()
	void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
	bool canAdd;

	canAdd = ((pos > 0) && (pos <= numItems + 1));
	if (canAdd)
	{
		if (numItems >= maxItems) {
			maxItems += CHUNK_SIZE;
			ItemType *tempList = new ItemType[maxItems];
			for (int i = 0; i < maxItems - CHUNK_SIZE; i++) {
				tempList[i] = list[i];
			}
			delete[] list;
			list = tempList;
		}
		for (int i = numItems; i >= pos; i--)
			list[i] = list[i - 1];

		// now put our item at position pos-1
		list[pos - 1] = item;

		numItems++;
	}

	return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
	if (pos<1 || pos>getLength()) {
		throw invalid_argument("ERROR: getEntry() using invalid position");
	}
	return list[pos - 1];
}

// implementations for setEntry() and remove() functions
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item) {
	if (pos<1 || pos>getLength()) {
		throw invalid_argument("ERROR: setEntry() using invalid position");
	}
	list[pos - 1] = item;
}

template<class ItemType>
bool List<ItemType>::remove(int pos) {
	bool canRemove;

	canRemove = ((pos > 0) && (pos <= numItems));

	if (canRemove)
	{

		for (int i = pos-1; i < numItems-1; i++)
			list[i] = list[i+1];

		numItems--;
	}
	return canRemove;

}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
	bool inputCheck;
	int trackNumber;

	do
	{
		inputCheck = true;
		cout << "Please enter the track number you'd like to view: ";
		if (!(cin >> trackNumber))
		{
			cout << "Please enter numbers only.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			inputCheck = false;
		}
	} while (!inputCheck);
	return trackNumber;
}


int main()
{
	List<string> songs;
	string done;
	// Insert some songs into our list

	cout << "songs.insert(1, Song1)" << songs.insert(1, "Song4") << endl;
	cout << "songs.insert(1, Song2)" << songs.insert(1, "Song3") << endl;
	cout << "songs.insert(1, Song3)" << songs.insert(1, "Song2") << endl;
	cout << "songs.insert(1, Song4)" << songs.insert(1, "Song1") << endl;
	cout << "songs.getEntry(1): " << songs.getEntry(1) << endl;
	cout << "songs.getEntry(2): " << songs.getEntry(2) << endl;
	cout << "songs.getEntry(3): " << songs.getEntry(3) << endl;
	cout << "songs.getEntry(4): " << songs.getEntry(4) << endl;
	cout << "songs.getEntry(5): " << endl;
	try { songs.getEntry(5); }
	catch (invalid_argument arg)
	{
		cout << arg.what() << endl;
	}
	cout << "songs.setEntry(1, changedSong)"<<endl;
	songs.setEntry(1, "changedSong");
	cout << "songs.getEntry(1): " << songs.getEntry(1) << endl;
	cout << "songs.setEntry(5, changedSong): " << endl;
	try { songs.setEntry(5,"changedSong"); }
	catch (invalid_argument arg)
	{
		cout << arg.what() << endl;
	}
	cout << "songs.getEntry(1): " << songs.getEntry(1) << endl;
	cout << "songs.getEntry(2): " << songs.getEntry(2) << endl;
	cout << "songs.getEntry(3): " << songs.getEntry(3) << endl;
	cout << "songs.getEntry(4): " << songs.getEntry(4) << endl;
	//cout << "songs.remove(1): "<< endl;
	songs.remove(1);
	cout << "songs.getEntry(1): " << songs.getEntry(1) << endl;
	cout << "songs.getEntry(2): " << songs.getEntry(2) << endl;
	cout << "songs.getEntry(3): " << songs.getEntry(3) << endl;
	cin >> done;
	return 0;
}
