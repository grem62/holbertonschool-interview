#!/usr/bin/python3

def count_words(subreddit, word_list):
    """
    Queries the Reddit API, parses the title of all hot articles, and prints
    a sorted count of given keywords.

    Args:
        subreddit (str): The subreddit to search.
        word_list (list): The list of keywords to search for.

    Returns:
        None
    """
    import requests

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Mozilla/5.0"}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code != 200:
        print(None)
        return

    response_json = response.json()
    data = response_json.get("data")
    children = data.get("children")
    titles = [child.get("data").get("title") for child in children]

    word_count = {}
    for title in titles:
        for word in word_list:
            if word.lower() in title.lower():
                if word in word_count:
                    word_count[word] += 1
                else:
                    word_count[word] = 1

    for word in sorted(word_count.keys()):
        print("{}: {}".format(word, word_count[word]))