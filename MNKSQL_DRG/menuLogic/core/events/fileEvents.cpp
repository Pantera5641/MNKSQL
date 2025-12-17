#include "fileEvents.h"


//-
void saveTxtEvent()
{
    clear();
    saveTxt("pipa");
    await();
}

//-
void saveBinEvent()
{
    clear();
    saveBin("pipa2");
    await();  
}

//-
void loadTxtEvent()
{
    clear();
    rewriteData(loadTxt("pipa"));
    await();
}

//-
void loadBinEvent()
{
    clear();
    rewriteData(loadBin("pipa2"));
    await();
}

//-
void convertTxtToBinEvent()
{
    clear();

    std::vector<Student> tempList {studentsList};

    rewriteData(loadTxt("pipa"));
    saveBin("pipa3");
    rewriteData(tempList);

    await();
}

//-
void convertBinToTxtEvent()
{
    clear();

    std::vector<Student> tempList {studentsList};

    rewriteData(loadBin("pipa1"));
    saveTxt("pipa4");
    rewriteData(tempList);

    await();
}