#!/usr/bin/python3
"""_summary_
    """


import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    """_summary_

    Args:
        subreddit (_type_): _description_
        word_list (_type_): _description_
        after (_type_, optional): _description_. Defaults to None.
        word_count (dict, optional): _description_. Defaults to {}.
    """
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after, 'limit': 100}

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data')
    children = data.get('children')

    for child in children:
        title = child.get('data').get('title').lower()
        for word in word_list:
            word_lower = word.lower()
            count = title.split().count(word_lower)
            if count > 0:
                if word_lower in word_count:
                    word_count[word_lower] += count
                else:
                    word_count[word_lower] = count

    after = data.get('after')
    if after is not None:
        count_words(subreddit, word_list, after, word_count)
    else:
        sorted_word_count = sorted(word_count.items(),
                                   key=lambda item: (-item[1], item[0]))
        for word, count in sorted_word_count:
            print(f"{word}: {count}")
