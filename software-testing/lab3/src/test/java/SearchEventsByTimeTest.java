import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;

import java.time.LocalDate;
import java.time.temporal.WeekFields;
import java.util.List;
import java.util.Locale;

import static org.junit.Assert.assertEquals;

public class SearchEventsByTimeTest extends SeleniumTest {

    private LocalDate getTimeFromElement(WebElement element){
        var eventTimeItem = element.findElement(By.xpath("//time"));
        var timeString = eventTimeItem.getAttribute("datetime").substring(0, 10); // first 10 characters is yyyy-mm-dd
        return LocalDate.parse(timeString);
    }

    private void selectMeetupTime(String time) {
        waitUntilClickable("//*[@id=\"dateRangeFilter\"]").click();
        waitUntilClickable("/html/body/reach-portal/div/div/div[@name=\"%s\"]".formatted(time)).click();
    }

    private List<WebElement> getEvents(){
        waitUntilReady("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]");
        return driver.findElements(By.xpath("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]/div"));
    }

    @Test
    public void searchMeetupTodayTest() {
        driver.get(SEARCH_URL);
        driver.manage().window().setSize(new Dimension(945, 1020));
        selectMeetupTime("Today");

        var currentDate = LocalDate.now();
        for (var event : getEvents()) {
            var time = getTimeFromElement(event);

            assertEquals(currentDate.getYear(), time.getYear());
            assertEquals(currentDate.getMonth(), time.getMonth());
            assertEquals(currentDate.getDayOfMonth(), time.getDayOfMonth());
        }
    }

    @Test
    public void searchMeetupTomorrowTest() {
        driver.get(SEARCH_URL);
        driver.manage().window().setSize(new Dimension(945, 1020));
        selectMeetupTime("Tomorrow");

        var currentDate = LocalDate.now();
        for (var event : getEvents()) {
            var time = getTimeFromElement(event);

            assertEquals(currentDate.getYear(), time.getYear());
            assertEquals(currentDate.getMonth(), time.getMonth());
            assertEquals(currentDate.getDayOfMonth() + 1 /* tomorrow */, time.getDayOfMonth());
        }
    }

    @Test
    public void searchMeetupThisWeekTest() {
        driver.get(SEARCH_URL);
        driver.manage().window().setSize(new Dimension(945, 1020));
        selectMeetupTime("This week");

        var weekFields = WeekFields.of(Locale.getDefault());
        var currentDate = LocalDate.now();
        var currentWeek = currentDate.get(weekFields.weekOfWeekBasedYear());

        for (var event : getEvents()) {
            var time = getTimeFromElement(event);
            var week = time.get(weekFields.weekOfWeekBasedYear());

            assertEquals(currentWeek, week);
        }
    }

    @Test
    public void searchMeetupNextWeekTest() {
        driver.get(SEARCH_URL);
        driver.manage().window().setSize(new Dimension(945, 1020));
        selectMeetupTime("Next week");

        var weekFields = WeekFields.of(Locale.getDefault());
        var currentDate = LocalDate.now();
        var currentWeek = currentDate.get(weekFields.weekOfWeekBasedYear());

        for (var event : getEvents()) {
            var time = getTimeFromElement(event);
            var week = time.get(weekFields.weekOfWeekBasedYear());

            assertEquals(currentWeek + 1, week);
        }
    }
}
