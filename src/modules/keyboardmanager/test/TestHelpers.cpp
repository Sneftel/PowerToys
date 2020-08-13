#include "pch.h"
#include "TestHelpers.h"
#include "MockedInput.h"
#include "keyboardmanager/common/KeyboardManagerState.h"

namespace TestHelpers
{
    // Function to reset the environment variables for tests
    void ResetTestEnv(MockedInput& input, KeyboardManagerState& state)
    {
        input.ResetKeyboardState();
        input.SetHookProc(nullptr);
        input.SetSendVirtualInputTestHandler(nullptr);
        input.SetForegroundProcess(L"");
        state.ClearSingleKeyRemaps();
        state.ClearOSLevelShortcuts();
        state.ClearAppSpecificShortcuts();

        // Allocate memory for the keyboardManagerState activatedApp member to avoid CRT assert errors
        std::wstring maxLengthString;
        maxLengthString.resize(MAX_PATH);
        state.SetActivatedApp(maxLengthString);
        state.SetActivatedApp(KeyboardManagerConstants::NoActivatedApp);
    }

    // Function to return the index of the given key code from the drop down key list
    int GetDropDownIndexFromDropDownList(DWORD key, const std::vector<DWORD>& keyList)
    {
        return (int)std::distance(keyList.begin(), std::find(keyList.begin(), keyList.end(), key));
    }
}
