import sys
from openai import OpenAI

# Replace with your actual API key
YOUR_API_KEY = "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"

# Initialize the client
client = OpenAI(api_key=YOUR_API_KEY, base_url="https://api.perplexity.ai")

def get_perplexity_response(prompt):
    messages = [
        {"role": "system", "content": "You are a helpful AI assistant."},
        {"role": "user", "content": prompt}
    ]

    try:
        response = client.chat.completions.create(
            model="llama-3-sonar-large-32k-online",
            messages=messages,
        )
        return response.choices[0].message.content
    except Exception as e:
        return f"An error occurred: {str(e)}"

def main():
    print("Welcome to the Perplexity AI CLI!")
    print("Type 'exit' to quit.")

    while True:
        user_input = input("\nYou: ")
        if user_input.lower() == 'exit':
            print("Goodbye!")
            sys.exit(0)
        
        print("\nPerplexity AI: ", end="")
        response = get_perplexity_response(user_input)
        print(response)

if __name__ == "__main__":
    main()
