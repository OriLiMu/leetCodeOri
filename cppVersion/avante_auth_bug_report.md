# Bug Report: Invalid Authentication Error with Moonshot AI (kimi-k2) in Avante Plugin

## Description
When using the Avante plugin in Neovim with Moonshot AI's kimi-k2 model, authentication fails with "Invalid Authentication" error, despite the same API key and URL working correctly in other applications like CherryStudio and Claude Code.

## Error Details
```
Error: {   message = "Invalid Authentication",   type = "invalid_authentication_error" }
```

## Environment
- **Neovim Version**: v0.11.2 (Build type: RelWithDebInfo, LuaJIT 2.1.1748459687)
- **Operating System**: Linux (Manjaro Linux)
- **Kernel**: 6.6.97-1-MANJARO #1 SMP PREEMPT_DYNAMIC Thu Jul 10 17:00:37 UTC 2025 x86_64 GNU/Linux
- **Plugin**: Avante (latest version)
- **AI Provider**: Moonshot AI (kimi-k2 model)

## Configuration
The following configuration is being used for Moonshot AI in Avante:
- **API Key**: [Verified working in other applications]
- **URL**: [Verified working in other applications]
- **Model**: kimi-k2

## Expected Behavior
Avante should successfully authenticate with Moonshot AI using the provided API key and URL, just like it does in CherryStudio and Claude Code.

## Actual Behavior
Authentication fails with "Invalid Authentication" error when attempting to use the kimi-k2 model through Avante.

## Verification Steps Taken
1. ✅ **API Key Verification**: The same API key works correctly in:
   - CherryStudio
   - Claude Code (k2-based)
2. ✅ **URL Verification**: The endpoint URL is correctly configured and accessible
3. ❌ **Avante Plugin**: Fails with authentication error

## Possible Causes
- Authentication header formatting issue in Avante's Moonshot AI integration
- Missing or incorrect Content-Type headers
- URL encoding issues in the request
- Potential API version mismatch between Avante and Moonshot AI
- Configuration parsing differences between applications

## Steps to Reproduce
1. Configure Avante with Moonshot AI (kimi-k2) credentials
2. Set the API key and URL (verified working in other applications)
3. Attempt to use any Avante functionality that requires API calls
4. Observe the "Invalid Authentication" error

## Additional Context
- The authentication credentials work perfectly in other AI clients
- This suggests the issue is specific to how Avante handles Moonshot AI authentication
- No proxy or network configuration issues as other applications work fine

## Suggested Investigation Areas
1. Check if Avante is sending the correct `Authorization` header format for Moonshot AI
2. Verify the request payload structure matches Moonshot AI's expectations
3. Compare the HTTP request structure between Avante and working clients like CherryStudio
4. Review if there are any recent changes in Moonshot AI's authentication requirements

## Labels
- bug
- authentication
- moonshot-ai
- kimi-k2
- high-priority