import java.io.File;
import java.io.FileNotFoundException;
import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.remote.RemoteWebDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.util.Arrays;

@RunWith(Parameterized.class)
public class SeleniumTest {
    protected static final int TIMEOUT = 5;
    protected static final String URL = "https://www.meetup.com/";
    protected static final String SEARCH_URL = "https://www.meetup.com/find/?keywords=.net";
    protected static final String CHROME_DRIVER_PATH = "src/test/resources/drivers/chromedriver.exe";
    protected static final String FIREFOX_DRIVER_PATH = "src/test/resources/drivers/geckodriver.exe";
    protected RemoteWebDriver driver;

    @Parameterized.Parameters
    public static Iterable<DriverType> data() {
        return Arrays.asList(DriverType.chrome, DriverType.firefox);
    }

    @Parameterized.Parameter
    public DriverType webDriverType;

    @BeforeClass
    public static void setupEnvironments(){
        var chromedriver = new File(CHROME_DRIVER_PATH).isFile();
        var firefoxdriver = new File(FIREFOX_DRIVER_PATH).isFile();
        if (!chromedriver.exists()) {
            throw new FileNotFoundException("Can't find chrome driver. Please download and move it to the src/resources directory: https://chromedriver.chromium.org/downloads");
        }
        if (!firefoxdriver.exists()) {
            throw new FileNotFoundException("Can't find firefox driver. Please download and move it to the src/resources directory: https://github.com/mozilla/geckodriver/releases");
        }

        System.setProperty("webdriver.chrome.driver", CHROME_DRIVER_PATH);
        System.setProperty("webdriver.gecko.driver", FIREFOX_DRIVER_PATH);
    }

    @Before
    public void setUpDrivers() throws Exception {
        switch (webDriverType){
            case chrome -> driver = new ChromeDriver();
            case firefox -> driver = new FirefoxDriver();
            default -> throw new Exception("Invalid web driver");
        }
    }

    @After
    public void tearDown() {
        driver.quit();
    }

    protected WebElement waitUntilReady(String xpath){
        return new WebDriverWait(driver, TIMEOUT).until(driver -> driver.findElement(By.xpath(xpath)));
    }

    protected WebElement waitUntilClickable(String xpath){
        return new WebDriverWait(driver, TIMEOUT).until(ExpectedConditions.elementToBeClickable(By.xpath(xpath)));
    }

    private enum DriverType {
        chrome,
        firefox
    }
}
