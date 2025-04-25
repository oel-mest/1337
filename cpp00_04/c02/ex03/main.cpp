#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void printTestResult(const char* testName, bool expected, bool result)
{
    std::cout << testName 
              << " - Expected: " << (expected ? "true" : "false")
              << ", Result: " << (result ? "true" : "false") 
              << std::endl;
}

int main()
{
    // Test 1: Point inside the triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(10.0f, 0.0f);
        Point c(5.0f, 10.0f);
        Point p(5.0f, 5.0f);
        bool expected = true;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 1", expected, result);
    }

    // Test 2: Point outside the triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(10.0f, 0.0f);
        Point c(5.0f, 10.0f);
        Point p(15.0f, 5.0f);
        bool expected = false;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 2", expected, result);
    }

    // Test 3: Point exactly at a vertex (should be false as it's not strictly inside).
    {
        Point a(0.0f, 0.0f);
        Point b(10.0f, 0.0f);
        Point c(5.0f, 10.0f);
        Point p(0.0f, 0.0f);
        bool expected = false;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 3", expected, result);
    }

    // Test 4: Point on the edge of the triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(10.0f, 0.0f);
        Point c(5.0f, 10.0f);
        Point p(5.0f, 0.0f); // Lies on the edge from (0,0) to (10,0)
        bool expected = false;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 4", expected, result);
    }

    // Test 5: Inside a small right triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point p(1.0f, 1.0f);
        bool expected = true;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 5", expected, result);
    }

    // Test 6: Outside a small right triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point p(5.0f, 5.0f);
        bool expected = false;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 6", expected, result);
    }

    // Test 7: Point on the boundary of a small triangle.
    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point p(2.5f, 0.0f);
        bool expected = false;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 7", expected, result);
    }

    // Test 8: Another inside test on a different triangle.
    {
        Point a(1.0f, 1.0f);
        Point b(4.0f, 1.0f);
        Point c(2.5f, 4.0f);
        Point p(2.5f, 2.0f);
        bool expected = true;
        bool result = bsp(a, b, c, p);
        printTestResult("Test 8", expected, result);
    }

    return 0;
}