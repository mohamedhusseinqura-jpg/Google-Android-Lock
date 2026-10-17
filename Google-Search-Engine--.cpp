#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct WebPage {
    string url;
    string title;
    vector<string> keywords;
    int clicks;
};

void searchGoogle(const vector<WebPage>& database, const string& query) {
    vector<WebPage> results;
    string lowerQuery = query;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    for (const auto& page : database) {
        for (string kw : page.keywords) {
            transform(kw.begin(), kw.end(), kw.begin(), ::tolower);
            if (kw == lowerQuery) {
                results.push_back(page);
                break;
            }
        }
    }

    sort(results.begin(), results.end(), [](const WebPage& a, const WebPage& b) {
        return a.clicks > b.clicks;
    });

    cout << "\n--- Google Search Results for: \"" << query << "\" ---" << endl;
    if (results.empty()) {
        cout << "No results found." << endl;
    } else {
        for (size_t i = 0; i < results.size(); ++i) {
            cout << i + 1 << ". " << results[i].title << " (" << results[i].url << ")" << endl;
        }
    }
}

int main() {
    vector<WebPage> googleIndex = {
        {"https://google.com", "Google Official Site", {"search", "google"}, 1000},
        {"https://youtube.com", "YouTube", {"video", "youtube", "google"}, 950},
        {"https://gmail.com", "Google Gmail", {"email", "gmail"}, 850}
    };

    searchGoogle(googleIndex, "google");
    return 0;
}
