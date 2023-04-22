#include <iostream>
#include <string>
#include <vector>
using namespace std;


void list_num(vector<int>num) 
{
	//lists out the numbers inside the vector
	for (int i : num)
	{

		cout << i << " ";

	}

}

int main() {

	int read_count = 0;
	vector<int>num = { 1,23,55 };

	while (true)
	{
		int new_num;
		int reader;
		int writer;
		//asks the number of readers to be entered
		cout << "Enter number of readers" << endl;
		cin >> reader;
		if (reader == 0) 
		{
			cout << "No readers waiting " << endl;
		}
		
		read_count++;
		//since there are readers wanting to enter, writers are not allowed in the crticial section
		if (read_count == 1)
		{
			cout << "Writers are waiting" << endl;


			//signal(mutex);
			//crtitical section
			int plus = 1;
			
			//in the critical section the readers read what is inside of the list 
			
			for (int j = 0; j < reader; j++)
			{
				cout << "Reader " << plus << " is reading list: ";
				list_num(num);
				cout << endl;
				plus++;
			}

			/* reading is performed */
			cout << "reading is performed" << endl;
		}
		//wait(mutex);
		//after the readers are done with their reading, the read_count is decremented,so that the writers can now enter
		read_count--;
		//allows for the readers to enter
		if (read_count == 0)
		{
			//signal(rw_mutex);
			cout << "Writer can now enter" << endl;
			int writer;

			//wait(rw_mutex);
			//asks for how many writers
			cout << "How many writers" << endl;
			cin >> writer;
			
			/* writing is performed */
			
			int order = 1;
			//writers enter new number to the list
			for (int i = 0; i < writer; i++)
			{
				cout << "Enter new number: ";
				cin >> new_num;
				num.push_back(new_num);
				cout << "reader " << order << " enters: " << new_num << endl;
				order++;
			}
			//signal(rw_mutex);
			//once all the writers have performed their duty the read_count increments 1 again, so readers can enter
			cout << "Writing is preformed" << endl;
		}
		
	//signal(mutex);
	}
	return 0;
}