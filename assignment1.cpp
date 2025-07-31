//Object Oriented menu driven bill searching 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Products
{
	private:
			int count = 0;
			string prod_name = "";
			int prod_price = 0;
	public:
			void setName(const string& name)
			{
				prod_name = name;
			}
			string getName()const
			{
				return prod_name;
			}
			void setPrice(const int& price)
			{
				prod_price = price;
			}
			int getPrice()const
			{
				return prod_price;
			}
			void accept_details()
			{
					cout << "Enter product name: " <<endl;
					cin >> prod_name;
					cout << "Enter price of product "<< endl;
					cin >> prod_price;
			}
			void display()
			{
				cout << prod_name << "|" <<"Price: $"<< prod_price << endl;
			}
		friend class Search;
};
class Search
{
	Products pr;
	Products b[10];
public:
	void input_bill()
	{
		cout << "How many products do you want to accept?"<<endl;
		cin >> pr.count;
		for(int i = 0; i < pr.count; i++)
		{
			b[i].accept_details();
		}
	}
	void display_bill()
	{
		cout << "Details of the products: \n";
		for(int i = 0; i < pr.count; i++)
		{
			b[i].display();
		}
	}
	void SentinelSearch()
				{
					string target;
					cout << "Enter the item you want to search for: ";
					cin >> target;
					string last = b[pr.count-1].getName();
					b[pr.count-1].setName(target);
					int i = 0;
					while(b[i].getName() != target)
						i++;
					b[pr.count-1].getName() = last;
					if(i < (pr.count-1) || (target == b[pr.count-1].getName()))
						cout << b[i].getName()<< "|" <<"Price: $"<< b[i].getPrice() << endl;
					else
						cout <<"Product not found!" << endl;
					cout << "Search algorithm used: SENTINEL SEARCH";
				}
	void LinearSearch()
				{
					string target;
					cout << "Enter the item you want to search for: ";
					cin >> target;
					int count = 0;
					for(int i = 0; i < pr.count; i++)
					{
						if(b[i].getName() == target)
						{
							cout << b[i].getName() << "|" <<"Price: $"<< b[i].getPrice() << endl;
							count++;
							break;
						}
					}
					if(count == 0)
						cout << "Product not found!" << endl;
					cout << "Search algorithm used: LINEAR SEARCH"<<endl;
				}
	void BinarySearch()
				{
					int cost;
					cout << "Enter cost of the item: " << endl;
					cin >> cost;
					for(int i = 0; i < pr.count-1; i++)
					{
						for(int j = 0; j < pr.count-i-1; j++)
						{
							if(b[j].getPrice() > b[j+1].getPrice())
							{
								int temp = b[j].getPrice();
								b[j].setPrice(b[j+1].getPrice());
								b[j+1].setPrice(temp);

								string temp1 = b[i].getName();
								b[i].setName(b[i+1].getName());
								b[i+1].setName(temp1);
							}
						}
					}
					int left = 0;
					int right = pr.count-1;
					while(left <= right)
					{
						int mid = static_cast<int>(floor((left+right)/2));
						if(b[mid].getPrice() == cost)
						{
							cout << "The item available at the given cost is: "<<b[mid].getName()<<"\nSearch algorithm used: BINARY SEARCH";
							return;
						}
						if(b[mid].getPrice() < cost)
							left = mid+1;
						else
							right = mid-1;
					}
					cout << "No item found." <<"\nSearch algorithm used: BINARY SEARCH"<< endl;
				}


};
int main()
{
	Search obj;
	obj.input_bill();
	int casee;
	cout << "Enter 1 for displaying all the products,2 for searching for the price of a specific product using sentinel search,\n3 for searching for a product using linear search and 4 for binary search.\n";
	cin >> casee;
	switch(casee)
	{
		case 1:
			obj.display_bill();
			break;
		case 2:
		{
			obj.SentinelSearch();
		}
		break;
		case 3:
		{
			obj.LinearSearch();
		}
		break;
		case 4:
		{
			obj.BinarySearch();
		}
		break;
		default:
			cout << "You can only enter 1,2 3 or 4.\n";
	}
	return 0;
}

