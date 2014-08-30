#include <gtest/gtest.h>
#include <Valid_Palindrome.h>

class ValidPalindrome : public :: testing :: Test {
public:
	Solution slu;
	ValidPalindrome() {}
};

TEST_F(ValidPalindrome, isPalindrome)
{
	string s1 = "";
	string s2 = "1a2";
	string s3 = "A man, a plan, a canal: Panama";
	ASSERT_EQ(slu.isPalindrome1(s1), true);
	ASSERT_EQ(slu.isPalindrome1(s2), false);
	ASSERT_EQ(slu.isPalindrome1(s3), true);
}
