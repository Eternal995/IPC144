#include <stdio.h>

#define WORD_LEN 20
#define VOCAL_LEN 100

struct Vocal
{
    char word[WORD_LEN + 1];
    // How long to hold the note (in seconds)
    int sustainTime;
};

struct Song
{
    char title[WORD_LEN + 1];
    char artist[WORD_LEN + 1];
    struct Vocal lyrics[VOCAL_LEN];
    int words;
};

int karaoke(const struct Song* song)
{
    int i, tSeconds = 0;
    struct Vocal word;

    printf("%s (by:%s)\n\n", song->title, song->artist);

    for (i = 0; i < song->words; i++)
    {
        word = song->lyrics[i];

        printf("%s ", word.word);

        if (word.sustainTime == 4)
        {
            puts("...");
        }

        tSeconds += word.sustainTime;
    }

    return tSeconds;
}

void convertMinSec(const int seconds, int* min, int* sec)
{
    *min = seconds / 60;
    *sec = seconds % 60;
}

int main(void)
{
    // !!! DO NOT MODIFY THE INITIALIZATION OF THE "chorus" VARIABLE !!!
    struct Song chorus = { "We Are The World", "Various Artists", {
        {"We", 1}, {"are", 1}, {"the", 1}, {"world", 4}, {"We", 1}, {"are", 1}, {"the", 1}, {"children", 4},
        {"We", 1}, {"are", 1}, {"the", 1}, {"ones", 1}, {"who", 1}, {"make", 1}, {"a", 1}, {"brighter", 2},
        {"day", 2}, {"so", 1},{"lets", 1}, {"start", 1}, {"giving", 4} }, 21 };

    int totalSeconds = karaoke(&chorus);
    int minutes = 0, seconds = 0;

    convertMinSec(totalSeconds, &minutes, &seconds);

    printf("Duration: %02d:%02d\n\n", minutes, seconds);

    return 0;
}