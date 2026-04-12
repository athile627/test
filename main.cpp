#include <iostream>

using namespace std;

int main()
{
/**
 *Unit tests for the Login class.
 *
 * This class tests:
 * Username validation
 * Password complexity vlidation
 * Cell phone format validation
 * Login functionality ( success and failure cases)
 */
 public class LoginTest {
//Create Login object to be used in all test cases
    Login login = new Login();

    @Test
    public void testUsernameCorrectlyFormatted() {
        assertTrue(login.checkUserName("kyl_1"));
    }
/**
*Test that an correctly Formatted username passes validation.
*/
Must contain"_"and be <=s characters
 */
    @Test
    public void testUsernameIncorrectlyFormatted() {
        assertFalse(login.checkUserName("kyle!!!!!!"));
    }

    @Test
    public void testPasswordMeetsComplexity() {
        assertTrue(login.checkPasswordComplexity("Ch&&sec@ke99!"));
    }

    @Test
    public void testPasswordDoesNotMeetComplexity() {
        assertFalse(login.checkPasswordComplexity("password"));
    }

    @Test
    public void testCellPhoneCorrectlyFormatted() {
        assertTrue(login.checkCellPhoneNumber("+27838968976"));
    }

    @Test
    public void testCellPhoneIncorrectlyFormatted() {
        assertFalse(login.checkCellPhoneNumber("08966553"));
    }

    @Test
    public void testLoginSuccessful() {
        login.registerUser("kyl_1", "Ch&&sec@ke99!", "+27838968976");
        assertTrue(login.loginUser("kyl_1", "Ch&&sec@ke99!"));
    }

    @Test
    public void testLoginFailed() {
        login.registerUser("kyl_1", "Ch&&sec@ke99!", "+27838968976");
        assertFalse(login.loginUser("wrong", "wrong"));
    }
}
import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {

        Login login = new Login();

        String username = JOptionPane.showInputDialog("Enter username:");
        String password = JOptionPane.showInputDialog("Enter password:");
        String cell = JOptionPane.showInputDialog("Enter SA cell number (+27...):");

        String registrationResult = login.registerUser(username, password, cell);
        JOptionPane.showMessageDialog(null, registrationResult);

        if (registrationResult.equals("User has been successfully registered.")) {

            String loginUsername = JOptionPane.showInputDialog("Login Username:");
            String loginPassword = JOptionPane.showInputDialog("Login Password:");

            boolean success = login.loginUser(loginUsername, loginPassword);

            String message = login.returnLoginStatus(success, "John", "Doe");
            JOptionPane.showMessageDialog(null, message);
        }
    }
}
