#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct node {
	node *right;
	node *left;
	int count;
	string str;
};
typedef node *tree;
void Init(tree &root)
{
	root = NULL;
}
bool isEmpty(tree root)
{
	return (root == NULL);
}
node *createNode(string str)
{
	node *p = new node;
	if (p == NULL) exit(1);
	p->str = str;
	p->count = 1;
	p->right = p->left= NULL;
	return p;
}
void insertNode(tree &root,string &str)
{
	if (root)
	{
		if (root->str == str) root->count++;
		 else if (root->str > str) insertNode(root->left, str);
		else insertNode(root->right, str);
	}
	else
	{
		node *p = createNode(str);
		root=new node;
		root = p;
	}
}
void output(tree root, fstream &f )
{
	if (root)
	{
		output(root->left, f);
		f<< root->str << "\t " << root->count << endl;
		output(root->right, f);
	}
}
void input(fstream &f,string &str)
{
		f >> str;
}
int main() {
	tree root;
	Init(root);
	
	fstream f,g;
       f.open("in.txt",ios::in);
	 g.open("out.txt",ios::out);
	string str="";
	while (!f.eof())
	{
		input(f, str);
		int s=str.length();
		if(str[s-1]==','||str[s-1]=='.'||str[s-1]=='!'||str[s-1]==')'||str[s-1]==';') str[s-1]='\0';
		else if(str[0]=='(') 
			for(int i=0;i<s;i++) str[i]=str[i+1];
	    insertNode(root, str);
	}
	output(root, g);
	f.close();
	g.close();
	return 0;
}
