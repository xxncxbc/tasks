#include <QtTest>
#include "../uitask/classes.h"

class classes_test : public QObject
{
    Q_OBJECT

public:
    classes_test();
    ~classes_test();

private slots:
    void test_prime();
    void test_factor();
    void test_sinus();
    void test_equation();
};

classes_test::classes_test() {}

classes_test::~classes_test() {}

void classes_test::test_prime() {
    prime x;
    QCOMPARE(x.isprime(1), false);
    QCOMPARE(x.isprime(10), false);
    QCOMPARE(x.isprime(31), true);
    QCOMPARE(x.isprime(100), false);
}

void classes_test::test_factor(){
    prime x;
    QCOMPARE(x.check(15), 15);
    QCOMPARE(x.check(13), 13);
    QCOMPARE(x.check(21), 21);
}

void classes_test::test_sinus(){
    taylor x;
    QCOMPARE(x.series(2, 0.01),  0.907936507937);
    QCOMPARE(x.series(0, 0.01), 0);
}

void classes_test::test_equation(){
    sq_eq x;
    vector<double> b = x.solve(1, 1, 1);
    vector<double> a = x.solve(1, -3, 2);
    vector<double> c = x.solve(1, 2, 1);
    QCOMPARE((1 * a[0] * a[0] - 3 * a[0] + 2), 0);
    QCOMPARE((1 * a[1] * a[1] - 3 * a[1] + 2), 0);
    QCOMPARE(b.size(), 0);
    QCOMPARE(c[0], c[1]);

}

QTEST_APPLESS_MAIN(classes_test);

#include "tst_classes_test.moc"
