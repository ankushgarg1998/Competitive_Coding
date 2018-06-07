for(int j=0; j<C; j++)
                {
                int chocoCol = 0;
                while(chocoCol < chocoPerCol)
                    {
                    chocoCol += chocoVr[j];
                    ++j;
                    }
                --j;
                if(chocoCol > chocoPerCol)
                    {
                    ans = 0;
                    break;
                    }
                }