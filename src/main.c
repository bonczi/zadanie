#include <stdio.h>

#define SAMPLE_SIZE 11

int
GetNext() {
  static int i = 0;
  static int sample_input[SAMPLE_SIZE] =
    { 0xf12, 0xea2, 0x684, 0x217, 0xfff, 0x1f5, 0xf12, 0xea2, 0x684, 0xfff,
    0x1f5
  };

  if (i < SAMPLE_SIZE)
      return sample_input[i++];
  else
      return -1;
}

int main(void)
{
	int table[SAMPLE_SIZE];
	int value;
	int temp;
	int even_value = 0u;
	int success = 0;

	for (int i = 0u; i < SAMPLE_SIZE; i++)
	{
		table[i] = GetNext();
	}

	for (int i = 0u; (i < SAMPLE_SIZE) && (success==0u); i++)
	{
		temp = table[i];

		for (int j=0u; (j <  SAMPLE_SIZE) && (even_value==0u); j++)
		{
			if (i != j)
			{
				if ( temp == table[j] )
				{
					even_value = 1u;
				}
			}
		}

		if (even_value == 0u)
		{
			success = 1u;
			value = temp;
		}
		else
		{
			even_value = 0u;
		}
	}

    if (success == 1u)
    {
    	printf("Searched value is: 0x%x\n",value);
    }
    else
    {
    	printf("Cannot find searched value\n");
    }



    return 0;


}
