#include "Headers.h"
#include "classStud.h"

using namespace CppUnit;

class TestBasicMath : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testVidurkis);
    CPPUNIT_TEST(testMediana);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testVidurkis(void);
    void testMediana(void);

private:

    Studentas *mTestObj;
};

//-----------------------------------------------------------------------------

void
TestBasicMath::testVidurkis(void)
{
    CPPUNIT_ASSERT(5 < mTestObj->Vidurkis());
}

void
TestBasicMath::testMediana(void)
{
    CPPUNIT_ASSERT(4 > mTestObj->Mediana());
}

void TestBasicMath::setUp(void)
{
    mTestObj = new Studentas();
}

void TestBasicMath::tearDown(void)
{
    delete mTestObj;
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main (int argc, char *argv[]){

    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
    cout << endl;

    int m = 0;
    bool sauga = 0;
    TipasC Studentai, Minksti;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> range(1, 10);

    cout << "Darbas su vector:" << endl;
    int dydis = 10;
    for (int i = 0; i < 5; i++){
        auto startas = std::chrono::system_clock::now();
        try {
            Generavimas (dydis);
            Skaitymas (dydis, m, Studentai);
            } catch (const char* msg){
                cout << msg << endl;
                sauga = 1;
                break;   
            }
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << dydis << "-ies dydzio failo generavimas ir skaitymas uztruko: " << uztruko << " sekundziu" << endl;
        dydis = dydis * 10;
    }
    if (sauga){
        cout << "Rusiavimas neivyko, del nuskaitymo arba irasymo klaidos" << endl;
    }
    else {
        {auto startas = std::chrono::system_clock::now();
        Minksti = Rusiavimas (Studentai);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << "Duomenu isrusiavimas uztruko: " << uztruko << " sekundziu" << endl;}
        
        {auto startas = std::chrono::system_clock::now();
        Irasymas (Minksti, Studentai);
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<
        std::chrono::duration<double> >(pabaiga - startas).count();
        cout << "Duomenu isvedimas uztruko: " << uztruko << " sekundziu" << endl;}
        cout << endl;
    }
    
    return 0;
}