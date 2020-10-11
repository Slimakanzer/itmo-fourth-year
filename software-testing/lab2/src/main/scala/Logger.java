import org.jetbrains.annotations.NotNull;

import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.List;

public class Logger {
    private final String[] header;
    private final String filepath;
    private OutputStreamWriter Writer;

    public Logger(@NotNull String[] header, @NotNull String filepath) {
        this.header = header;
        this.filepath = filepath;
    }

    public void Start() throws IOException {
        Writer = new FileWriter(filepath);

        String header = String.join(",", this.header);
        Writer.append(header);
        Writer.append(System.lineSeparator());
    }

    public void write(@NotNull List<Double> values) throws IOException, IllegalArgumentException{
        if (values.size() != header.length) throw new IllegalArgumentException("Values didn't match to header");

        StringBuilder sb = new StringBuilder();
        values.forEach(v -> sb.append(v).append(","));

        Writer.append(sb.toString());
        Writer.append(System.lineSeparator());
    }

    public void close() {
        try {
            if (Writer == null) return;
            Writer.flush();
            Writer.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
