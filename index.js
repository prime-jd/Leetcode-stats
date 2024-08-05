const express = require('express');
const axios = require('axios');

const app = express();
const PORT = process.env.PORT || 3000;

app.get('/leetcode/:username', async (req, res) => {
    const username = req.params.username;
    const url = `https://alfa-leetcode-api.onrender.com/${username}/solved`;  // Replace with your actual API endpoint

    try {
        // Fetch the LeetCode data
        const response = await axios.get(url);
        const data = response.data;

        const easy = data.easySolved || 0;
        const medium = data.mediumSolved || 0;
        const hard = data.hardSolved || 0;

        // Fetch additional data from the username API
        const userInfoUrl = `https://alfa-leetcode-api.onrender.com/${username}`;
        const userInfoResponse = await axios.get(userInfoUrl);
        const userInfo = userInfoResponse.data;

        const userDisplayName = userInfo.username || username;

        const svg = `
        <svg viewBox="0 0 400 200" xmlns="http://www.w3.org/2000/svg">
            <!-- Background -->
            <rect width="100%" height="100%" fill="#1a1a1a" rx="15" ry="15"/>

            <!-- Username -->
            <text x="50%" y="30" font-size="24" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif">
                ${userDisplayName}'s LeetCode Stats
            </text>

            <!-- Text -->
            <text x="50%" y="90" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif">
                Easy: ${easy}
            </text>
            <text x="50%" y="120" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif">
                Medium: ${medium}
            </text>
            <text x="50%" y="150" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif">
                Hard: ${hard}
            </text>

            <!-- 3D Effect -->
            <filter id="f1" x="0" y="0">
              <feOffset result="offOut" in="SourceAlpha" dx="5" dy="5" />
              <feGaussianBlur result="blurOut" in="offOut" stdDeviation="3" />
              <feBlend in="SourceGraphic" in2="blurOut" mode="normal" />
            </filter>

            <text x="50%" y="90" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif" filter="url(#f1)">
                Easy: ${easy}
            </text>
            <text x="50%" y="120" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif" filter="url(#f1)">
                Medium: ${medium}
            </text>
            <text x="50%" y="150" font-size="20" fill="#ffffff" text-anchor="middle" font-family="Arial, sans-serif" filter="url(#f1)">
                Hard: ${hard}
            </text>
        </svg>`;

        res.setHeader('Content-Type', 'image/svg+xml');
        res.send(svg);
    } catch (error) {
        res.status(500).send(`Error fetching data for ${username}: ${error.message}`);
    }
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
