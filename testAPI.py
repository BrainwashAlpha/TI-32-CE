from openai import OpenAI

# Replace with your actual API key
YOUR_API_KEY = "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"

# Initialize the client
client = OpenAI(api_key=YOUR_API_KEY, base_url="https://api.perplexity.ai")

# Define the messages
messages = [
    {
        "role": "system",
        "content": "You are a helpful AI assistant."
    },
    {
        "role": "user",
        "content": "What is the capital of France?"
    }
]

# Make the API call
response = client.chat.completions.create(
    model="llama-3-sonar-large-32k-online",
    messages=messages,
)

# Print the response
print(response.choices[0].message.content)




