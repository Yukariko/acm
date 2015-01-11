main()
{
	char bitStream[32];
	for(;gets(bitStream),bitStream[0] != '#';)
	{
		int pos,oneCount = 0;
		for(pos=0;bitStream[pos];pos++)
		{
			if(bitStream[pos] == '1') oneCount++;
		}
		bitStream[pos-1] = bitStream[pos-1] == 'e' ? oneCount % 2? '1': '0' : oneCount % 2? '0': '1';
		puts(bitStream); 
	}
}
