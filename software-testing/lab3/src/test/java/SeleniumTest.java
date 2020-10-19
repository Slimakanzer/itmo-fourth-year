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
    protected RemoteWebDriver driver;

    @Parameterized.Parameters
    public static Iterable<DriverType> data() {
        return Arrays.asList(DriverType.chrome, DriverType.firefox);
    }

    @Parameterized.Parameter
    public DriverType webDriverType;

    @BeforeClass
    public static void setupEnvironments(){
        System.setProperty("webdriver.chrome.driver", "src/test/resources/drivers/chromedriver.exe");
        System.setProperty("webdriver.gecko.driver", "src/test/resources/drivers/geckodriver.exe");
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
