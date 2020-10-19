import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;

import java.util.List;

import static org.junit.Assert.assertTrue;

public class SearchEventsTest extends SeleniumTest {
    private List<WebElement> getEventList(){
        waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]/div[1]");
        return driver.findElements(By.xpath("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]/div"));
    }

    @Test
    public void searchMoreEventsButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));
        waitUntilClickable("//*[@id=\"tracking--searchComponentInput\"]").sendKeys(".net");
        waitUntilClickable("//*[@id=\"tracking--searchComponentButton\"]").click();

        var events = getEventList();
        for (int i = 0; i < 3; i++) {
            driver.findElement(By.xpath("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[2]/button")).click();
            waitUntilClickable(String.format("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]/div[%d]", events.size() + 1));
            var newEvents = getEventList();

            assertTrue(newEvents.size() > events.size());
            assertTrue(newEvents.containsAll(events));

            events = newEvents;
        }
    }
}
