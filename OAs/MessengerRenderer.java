import java.util.ArrayList;
import java.util.List;

public class MessengerRenderer {

    private static String repeatString(String s, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) {
            sb.append(s);
        }
        return sb.toString();
    }

    public static String[] renderMessenger(String[][] messages, int width, int userWidth) {
        List<String> res = new ArrayList<>();
        res.add("+" + repeatString("*", width) + "+");

        for (String[] message : messages) {
            String user = message[0];
            String msg = message[1];
            String[] words = msg.split(" ");

            List<String> lines = new ArrayList<>();
            String line = "";
            for (String word : words) {
                if (line.isEmpty()) {
                    line = word;
                } else if (line.length() + 1 + word.length() <= userWidth) {
                    line += " " + word;
                } else {
                    lines.add(line);
                    line = word;
                }
            }

            if (!line.isEmpty()) {
                lines.add(line);
            }

            for (String l : lines) {
                if (user.equals("1")) {
                    res.add("|" + l + repeatString(" ", width - l.length()) + "|");
                } else {
                    res.add("|" + repeatString(" ", width - l.length()) + l + "|");
                }
            }
        }

        res.add("+" + repeatString("*", width) + "+");
        String[] resArray = new String[res.size()];
        resArray = res.toArray(resArray);

        return resArray;
    }

    public static void main(String[] args) {
        String[][] messages = {
            {"1", "Hello how r u"},
            {"2", "Good ty"},
            {"2", "u"},
            {"1", "me too bro"}
        };

        int width = 15;
        int userWidth = 5;
        String[] res = renderMessenger(messages, width, userWidth);

        for (String s : res) {
            System.out.println(s);
        }
    }
}
