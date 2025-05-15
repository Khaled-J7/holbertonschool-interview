#!/usr/bin/python3
"""
Module to query the Reddit API and count occurrences of keywords in hot post titles
"""
import requests


def count_words(subreddit, word_list, after=None, word_counts=None):
    """
    Recursively queries the Reddit API, parses the titles of all hot articles,
    and prints a sorted count of given keywords.

    Args:
        subreddit (str): The subreddit to search
        word_list (list): List of keywords to count
        after (str, optional): Token for pagination. Defaults to None.
        word_counts (dict, optional): Dictionary to track keyword counts.
                                      Defaults to None.

    Returns:
        None: Results are printed, nothing is returned.
    """
    # Initialize word_counts on first call
    if word_counts is None:
        # Convert keywords to lowercase and create dictionary
        word_counts = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower in word_counts:
                word_counts[word_lower] += 0
            else:
                word_counts[word_lower] = 0

    # Set up headers and parameters for the API request
    headers = {"User-Agent": "Custom User Agent 1.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    # Make request to Reddit API
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    response = requests.get(url, headers=headers, params=params, allow_redirects=False)

    # Check if the subreddit is valid
    if response.status_code != 200:
        return

    # Parse the response
    data = response.json().get("data", {})
    children = data.get("children", [])
    after = data.get("after")

    # Process each post title
    for child in children:
        title = child.get("data", {}).get("title", "").lower()
        # Split the title into words and remove punctuation
        words = title.split()
        words = [word.strip(".,!?;:'\"()[]{}-_=+") for word in words]

        # Count keyword occurrences
        for word in words:
            for key in word_counts.keys():
                if word == key:
                    word_counts[key] += 1

    # If there are more pages, make recursive call
    if after:
        return count_words(subreddit, word_list, after, word_counts)
    else:
        # Sort and print results
        sorted_counts = sorted(
            [(key, value) for key, value in word_counts.items() if value > 0],
            key=lambda x: (-x[1], x[0]),
        )

        for keyword, count in sorted_counts:
            print(f"{keyword}: {count}")
