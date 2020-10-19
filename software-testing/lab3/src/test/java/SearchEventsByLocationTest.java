import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;

import static org.junit.Assert.assertEquals;

public class SearchEventsByLocationTest extends SeleniumTest {

    @Test
    public void searchEventsByLocation(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[1]/div/div[6]/div[2]/div[1]/div[1]/div/div[2]/div/input").clear();
        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[1]/div/div[6]/div[2]/div[1]/div[1]/div/div[2]/div/input").sendKeys("St. Petersburg");
        waitUntilClickable("//reach-portal//li[1]").click();
        driver.findElement(By.xpath("//*[@id=\"tracking--searchComponentButton\"]")).click();

        var searchName = waitUntilReady("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/h1").getText();
        assertEquals("Events near St. Petersburg, RU", searchName);
    }
}