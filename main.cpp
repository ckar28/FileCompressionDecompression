#include "FrequencyCounter.h"
#include "Huffman.h"


std::ifstream::pos_type filesize(const char* filename);

int main()
{
    FrequencyCounter frequencyCounter ;
    Huffman huffman;
    cout<<"Press 1 to compress and 2 to decompress::";
    int choice=0;
    cin>>choice;
    if(choice == 1)
    {
        clock_t tStart = clock();
        frequencyCounter.readFile("input.txt");
        huffman.huffer(frequencyCounter.getFrequencyMap());
        huffman.compressTofile("input.txt","output.txt");
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File Size : "<<filesize("input.txt")<<" bytes."<<endl;
        cout<< "Compressed File Size : "<<filesize("output.txt")<<" bytes."<<endl;
        cout<< "Compression Ratio : "<<(1.0*filesize("output.txt")/filesize("input.txt"))<<endl;
    }
    else if(choice == 2)
    {
        clock_t tStart = clock();
        huffman.deHuffer("output.txt","output2.txt");
        cout <<"Time taken: "<<(1.0*(clock() - tStart)/CLOCKS_PER_SEC)<<"sec"<<endl;
        cout << "Input File (Compressed) Size : "<<filesize("output.txt")<<" bytes."<<endl;
        cout<< "DeCompressed File Size : "<<filesize("output2.txt")<<" bytes."<<endl;
    }


    return 0;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}