#include "lexeme.cpp"
#include "ss.cpp"

 
int main (int argc, char* argv[])
{
	try
	{
		cout.width(15);
		cout << "_code_";
		cout.width(20);
		cout << "type_of_lex";
		cout.width(10);
		cout << "val";
		cout.width(5);
		cout << "str";
		cout.width(5);
		cout << "chr"<< endl;
		// cout << "The lexical stage:" << endl;
		// Lex curr_lex;
		// Scanner scan (argv[1]);
		// curr_lex = scan.get_lex();
		// while( curr_lex.get_type() != 17 )
		// {
		// 	cout << endl;
		// 	curr_lex = scan.get_lex();
		// }
		// cout << "The syntactic stage:" << endl;
		Parser   pars(argv[1]);
		pars.analyze ();
		
		return 0;
	}
	catch (char c)
	{
		cout << "unexpected symbol: " << c << endl;
		return 1;
	}
	catch (Lex l)
	{
		cout << argv[1] << ", " << l.get_str() << ", " << l.get_chr();
		cout << ": ERROR: unexpected lexeme: " << l;
		return 1;
	}
	catch ( const char *source )
	{
		cout << source << endl;
		return 1;
	}
}