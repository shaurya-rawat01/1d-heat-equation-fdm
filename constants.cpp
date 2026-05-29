#include "constants.h"

///Function to write vector into dat file
void write_vector(const vector<double>& v)
{
	cout<<"\nEnter filename\n";
	string filename;
	cin>>filename;
	
	filename += ".dat";
	
	ofstream ofs;
	ofs.open(filename.c_str());
	
	for (int i = 0;i<v.size();i++)
		ofs<<v[i]<<endl;
		
	ofs.close();
}
