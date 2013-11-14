
int
main()
{
	int i, j, arr[size][size];
	srand((unsigned int) time(NULL));
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			arr[i][j] = rand() % limit;
	}
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			cout<<setw(2)<<arr[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
