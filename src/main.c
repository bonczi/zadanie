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

static int copy_to_table(int * ptr);
static int compare_value(int * ptr, int * value);

int main(void)
{
    int table[SAMPLE_SIZE];
    int value;
    int success;

    success = copy_to_table(table);

    if ( success )
    {
        success = compare_value(table, &value);
    }

    if (success )
    {
        printf("Searched value is: 0x%x\n",value);
    }
    else
    {
        printf("Cannot find searched value\n");
    }

    return 0;

}


static int copy_to_table(int * ptr)
{
    int success = 0u;

    if (ptr != NULL)
    {
        for (int i = 0u; i < SAMPLE_SIZE; i++)
        {
            ptr[i] = GetNext();
        }
        success = 1u;
    }
    else
    {
        printf("Invalid address of table");
    }

    return success;
}


static int compare_value(int * ptr, int * value)
{
    int temp;
    int even_value = 0u;
    int success = 0;

    if ( (ptr != NULL)
        && (value != NULL) )
    {
        for (int i = 0u; (i < SAMPLE_SIZE) && (success==0u); i++)
        {
            temp = ptr[i];

            for (int j=0u; (j <  SAMPLE_SIZE) && (even_value==0u); j++)
            {
                if (i != j)
                {
                    if ( temp == ptr[j] )
                    {
                        even_value = 1u;
                    }
                }
            }

            if (even_value == 0u)
            {
                success = 1u;
                *value = temp;
            }
            else
            {
                even_value = 0u;
            }
        }
    }
    else
    {
        printf("Invalid address of table or return value");
    }

    return success;
}
