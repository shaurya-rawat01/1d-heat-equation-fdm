#include "Solver.h"
#include "Analysis.h"
#include <stdexcept>

int main()
{
	EquationData E(delta_x, delta_t, max_time);
	E.dispParam();
	cout<<"\nDo you wish to customize parameters? (y/n) \n";
	char response;
	cin>>response;
	switch(toupper(response))
	{
		case 'Y':
			E.updateParam();
			break;
		
		case 'N':
			break;
			
		default: 
			throw out_of_range("Invalid Choice");
	}
	
	cout<<endl;
	solve(E);
	cout<<endl;
	Analysis A(E);
	return 0;
}

